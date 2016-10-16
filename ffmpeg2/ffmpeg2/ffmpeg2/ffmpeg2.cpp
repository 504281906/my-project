#include "ffmpeg.h"

AVFormatContext *ic=NULL,*oc;
AVStream *video_st = NULL;
AVStream *audio_st = NULL;
AVBitStreamFilterContext * vbsf_aac_adtstoasc = NULL;
AVBitStreamFilterContext * vbsf_h264_toannexb = NULL;
int video_stream_index=-1,audio_stream_index=-1;
int IsAACCodes = 0;

unsigned int m_output_index = 1;       //生成的切片文件顺序编号
char m_output_file_name[256];          //输入的要切片的文件

/*---输入信息，准备自定义，以后再写清楚---*/
void display_usage(void)
{
    printf("使用切片工具帮助\n");
    printf("\n");
    printf("HTTP直播流，将音视频文件切片并创建m3u8文件");
    printf("\n");
    printf("\t-i, --input FILE             音视频文件名\n");
    printf("\t-d, --duration SECONDS       每个切片时间\n");
    printf("\t-p, --output-prefix PREFIX   TS文件前缀\n");
    printf("\t                             with -1.ts, -2.ts etc\n");
    printf("\t-m, --m3u8-file FILE         M3U8输出文件名\n");
    printf("\t-u, --url-prefix PREFIX      网络地址前缀，例如 http://example.org/video/\n");
    printf("\t-n, --num-segment NUMBER     切片文件个数，一般不设置\n");
    printf("\t-h, --help                   查看帮助\n");
    printf("\n");
    printf("\n");

    exit(0);
}

void init_input(int argc,char **argv)
{
	static char *optstring = "i:d:p:m:u:n:ovh?";
	memset(&options, 0 ,sizeof(options));
	char *endptr;
	int opt;
	do {
        opt = getopt(argc, argv, optstring);
        switch (opt) {
			//输入文件
            case 'i':
                options.input_file = optarg;
                break;
			//切片时间
            case 'd':
                options.segment_duration = strtol(optarg, &endptr, 10);
                if (optarg == endptr || options.segment_duration < 0 || options.segment_duration == -LONG_MAX) {
                    fprintf(stderr, "Segment duration time (%s) invalid\n", optarg);
                    exit(1);
                }
                break;
			//输出文件前缀
            case 'p':
                options.output_prefix = optarg;
                break;
			//m3u8文件名
            case 'm':
                options.m3u8_file = optarg;
                break;
			//上传地址
            case 'u':
                options.url_prefix = optarg;
                break;
			//切片个数
            case 'n':
                options.num_segments = strtol(optarg, &endptr, 10);
                if (optarg == endptr || options.num_segments < 0 || options.num_segments >= LONG_MAX) {
                    fprintf(stderr, "Maximum number of ts files (%s) invalid\n", optarg);
                    exit(1);
                }
                break;
			//查看帮助信息
            case 'h':
                display_usage();
                break;
        }
    } while (opt != -1);
}

/*初始化解复用器*/
int init_demux(const char *filename,AVFormatContext **ic)
{
	if (avformat_open_input(ic,filename,NULL,NULL) < 0)
	{
		printf("avformat_open_input函数调用失败\n");
		return -1;
	}
	if (avformat_find_stream_info(*ic,NULL) < 0)
	{
		printf("没有找到输入文件流信息\n");
		return -1;
	}
	//输出文件流信息
	av_dump_format(*ic,-1,filename,0);
	
	//添加音视频信息
	for (int i=0;i<((*ic)->nb_streams);i++)
	{
		if ((*ic)->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO)
		{
			audio_stream_index = i;
		}
		if ((*ic)->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			video_stream_index = i;
		}
	}

	if ((strstr((*ic)->iformat->name, "flv") != NULL) || 
		(strstr((*ic)->iformat->name, "mp4") != NULL) || 
		(strstr((*ic)->iformat->name, "mov") != NULL))
	{
		if ((*ic)->streams[video_stream_index]->codec->codec_id == AV_CODEC_ID_H264)  //AV_CODEC_ID_H264
		{
			//这里可能有点问题，H264有两种封装格式...
			//这里注意："h264_mp4toannexb",一定是这个字符串，无论是 flv，mp4，mov格式
			vbsf_h264_toannexb = av_bitstream_filter_init("h264_mp4toannexb"); 
		} 
		if ((*ic)->streams[audio_stream_index]->codec->codec_id == AV_CODEC_ID_AAC) //AV_CODEC_ID_AAC
		{
			IsAACCodes = 1;
		}
	}
	return 0;
}

AVStream *add_out_stream(AVFormatContext *output_format_context,AVMediaType codec_type_t)
{
	AVStream *input_stream = NULL;
	AVStream *output_stream = NULL;
	AVCodecContext *output_codec_context = NULL;

	output_stream = avformat_new_stream(output_format_context,NULL);
	if (!output_stream)
	{
		printf("avformat_new_stream函数调用失败\n");
		exit(1);
	}
	switch(codec_type_t)
	{
	case AVMEDIA_TYPE_AUDIO:
		input_stream = ic->streams[audio_stream_index];
		break;
	case AVMEDIA_TYPE_VIDEO:
		input_stream = ic->streams[video_stream_index];
		break;
	default:
		break;
	}
	output_stream->id = output_format_context->nb_streams-1;
	output_codec_context = output_stream->codec;
	output_stream->time_base = input_stream->time_base;

	if (avcodec_copy_context(output_stream->codec,input_stream->codec) < 0)
	{
		printf("avcodec_copy_context函数调用失败\n");
		exit(1);
	}
	//这个很重要，要么纯复用解复用，不做编解码写头会失败,
	//另或者需要编解码如果不这样，生成的文件没有预览图，还有添加下面的header失败，置0之后会重新生成extradata
	output_codec_context->codec_tag = 0; 
	if(AVFMT_GLOBALHEADER & output_format_context->oformat->flags)
	{
		output_codec_context->flags |= CODEC_FLAG_GLOBAL_HEADER;
	}
	return output_stream;
}

int init_mux()
{
	avformat_alloc_output_context2(&oc,NULL,NULL,m_output_file_name);
	if (!oc)
	{
		printf("avformat_alloc_output_context2函数调用失败\n");
		return -1;
	}
	AVOutputFormat *ofmt = NULL;
	ofmt = oc->oformat;

	if (!(ofmt->flags & AVFMT_NOFILE))
	{
		if (avio_open(&oc->pb, m_output_file_name, AVIO_FLAG_WRITE) < 0)
		{
			printf("不能打开文件'%s'\n", m_output_file_name);
			return -1;
		}
	}

	if (audio_stream_index != -1)
		audio_st = add_out_stream(oc, AVMEDIA_TYPE_AUDIO);
	if (video_stream_index != -1)
		video_st = add_out_stream(oc, AVMEDIA_TYPE_VIDEO);
	
	//输出oc流看看
	av_dump_format(oc, 0, m_output_file_name, 1);

	if (avformat_write_header(oc,NULL) < 0)
	{
		printf("又是这个鬼avformat_write_header失败\n");
		return -1;
	}
	return 0;
}

/*-写入信息-*/
int write_index_file(const unsigned int first_segment, const unsigned int last_segment, const int end, const unsigned int actual_segment_durations[])
{
	FILE *index_fp = NULL;
	char *write_buf = NULL;
	char m3u8_file_pathname[256] ={0};

	sprintf(m3u8_file_pathname,"%s%s",options.url_prefix,options.m3u8_file);
	index_fp = fopen(m3u8_file_pathname,"w");
	if (!index_fp)
	{
		printf("文件打不开啊\n");
		return -1;
	}
	write_buf = (char *)malloc(sizeof(char)*1024);
	if (!write_buf)
	{
		printf("分配内存失败啊\n");
		return -1;
	}

	if (NUM_SEGMENTS)
	{
		//#EXT-X-MEDIA-SEQUENCE：<Number> 播放列表文件中每个媒体文件的URI都有一个唯一的序列号。URI的序列号等于它之前那个RUI的序列号加一(没有填0)
		sprintf(write_buf,"#EXTM3U\n#EXT-X-TARGETDURATION:%lu\n#EXT-X-MEDIA-SEQUENCE:%u\n",options.segment_duration,first_segment);
	}
	else 
	{
		sprintf(write_buf,"#EXTM3U\n#EXT-X-TARGETDURATION:%lu\n",options.segment_duration);
	}

	if (fwrite(write_buf,strlen(write_buf),1,index_fp) != 1)
	{
		printf("写不了啊\n");
		free(write_buf);
		fclose(index_fp);
		return -1;
	}
	for (int i = first_segment; i <= last_segment; i++) 
	{
		sprintf(write_buf,"#EXTINF:%u,\n%s%s-%u.ts\n",actual_segment_durations[i-1],options.url_prefix,options.output_prefix,i);
		if (fwrite(write_buf,strlen(write_buf),1,index_fp) != 1)
		{
			printf("写不了啊\n");
			free(write_buf);
			fclose(index_fp);
			return -1;
		}
	}
	if(end)
	{
		sprintf(write_buf,"#EXT-X-ENDLIST\n");
		if (fwrite(write_buf,strlen(write_buf),1,index_fp) != 1)
		{
			printf("写不了啊\n");
			free(write_buf);
			fclose(index_fp);
			return -1;
		}
	}
	free(write_buf);
	fclose(index_fp);
	return 0;
}

int uinit_mux()
{
	if (av_write_trailer(oc) < 0)
	{
		printf("Call av_write_trailer function failed\n");
	}
	if (vbsf_aac_adtstoasc !=NULL)
	{
		av_bitstream_filter_close(vbsf_aac_adtstoasc); 
		vbsf_aac_adtstoasc = NULL;
	}

	/* 释放流 */
	for (int i = 0; i < oc->nb_streams; i++) 
	{
		av_freep(&oc->streams[i]->codec);
		av_freep(&oc->streams[i]);
	}
	if (!(oc->oformat->flags & AVFMT_NOFILE))
	{
		/* 关闭输出文件. */
		avio_close(oc->pb);
	}
	av_free(oc);
	return 1;
}

/*---开始切片---*/
void go()
{
	int write_index = 1;
	unsigned int first_segment = 1;     //第一个分片的标号
	unsigned int last_segment = 0;      //最后一个分片标号
	int decode_done = 0;                //文件是否读取完成
	int remove_file = 0;                //是否移除文件。无聊的属性
	char *remove_filename;    //要从磁盘上删除的文件名称
	double prev_segment_time = 0;       //上一个分片时间
	unsigned int actual_segment_durations[1024] = {0}; //各个分片文件实际的长度

	//填写第一个切片文件名称
	sprintf(m_output_file_name,"%s%s-%u.ts",options.url_prefix,options.output_prefix,m_output_index++);

	//重点写头部，几次都挂在这里
	init_mux();

	write_index = !write_index_file(first_segment,last_segment,0,actual_segment_durations);
	do
	{
		unsigned int current_segment_duration;
		double segment_time = prev_segment_time;
		AVPacket packet;
		av_init_packet(&packet);
		decode_done = av_read_frame(ic,&packet);
		if (decode_done < 0)
			break;
		if (av_dup_packet(&packet) < 0)
		{
			printf("不能读取包的信息");
			av_free_packet(&packet);
			break;
		}
		if (packet.stream_index == video_stream_index)
			segment_time = packet.pts * av_q2d(ic->streams[video_stream_index]->time_base);
		else if (packet.stream_index == audio_stream_index) 
			segment_time = packet.pts * av_q2d(ic->streams[audio_stream_index]->time_base);
		else 
			segment_time = prev_segment_time;

		//这里是为了纠错，有文件pts为不可用值
		if (packet.pts < packet.dts)
		{
			packet.pts = packet.dts;
		}

		//视频
		if (packet.stream_index == video_stream_index)
		{
			if (vbsf_h264_toannexb != NULL)
			{
				AVPacket filteredPacket = packet;
				int a = av_bitstream_filter_filter(vbsf_h264_toannexb,video_st->codec,NULL,&filteredPacket.data, &filteredPacket.size, 
					packet.data, packet.size, packet.flags & AV_PKT_FLAG_KEY);
				if (a > 0)
				{
					av_free_packet(&packet);
					packet.pts = filteredPacket.pts;
					packet.dts = filteredPacket.dts;
					packet.duration = filteredPacket.duration;
					packet.flags = filteredPacket.flags;
					packet.stream_index = filteredPacket.stream_index;
					packet.data = filteredPacket.data;  
					packet.size = filteredPacket.size;    
				}else if (a < 0)            
				{                
					fprintf(stderr, "%s failed for stream %d, codec %s",
						vbsf_h264_toannexb->filter->name,packet.stream_index,video_st->codec->codec ?  video_st->codec->codec->name : "copy");
					av_free_packet(&packet);                
					getchar();           
				}
			}
			packet.pts = av_rescale_q_rnd(packet.pts, ic->streams[video_stream_index]->time_base, video_st->time_base, AV_ROUND_NEAR_INF);
			packet.dts = av_rescale_q_rnd(packet.dts, ic->streams[video_stream_index]->time_base, video_st->time_base, AV_ROUND_NEAR_INF);
			packet.duration = av_rescale_q(packet.duration,ic->streams[video_stream_index]->time_base, video_st->time_base);
			packet.stream_index = VIDEO_ID; //这里add_out_stream顺序有影响
			//printf("video\n");
		}
		else if (packet.stream_index == audio_stream_index)
		{
			packet.pts = av_rescale_q_rnd(packet.pts, ic->streams[audio_stream_index]->time_base, audio_st->time_base, AV_ROUND_NEAR_INF);
			packet.dts = av_rescale_q_rnd(packet.dts, ic->streams[audio_stream_index]->time_base, audio_st->time_base, AV_ROUND_NEAR_INF);
			packet.duration = av_rescale_q(packet.duration,ic->streams[audio_stream_index]->time_base, audio_st->time_base);
			packet.stream_index = AUDIO_ID; //这里add_out_stream顺序有影响
			//printf("audio\n");
		}
		current_segment_duration = (int)(segment_time - prev_segment_time + 0.5);
		actual_segment_durations[last_segment] = (current_segment_duration > 0 ? current_segment_duration: 1);

		if (segment_time - prev_segment_time >= options.segment_duration)
		{
			if (av_write_trailer(oc))
			{
				printf("警告：不能写入流信息\n");
			}
			avio_flush(oc->pb);
			avio_close(oc->pb);

			if (NUM_SEGMENTS && (int)(last_segment - first_segment) >= NUM_SEGMENTS - 1)
			{
				remove_file = 1;
				first_segment++;
			}else remove_file = 0;
			if (write_index) 
			{
				write_index = !write_index_file(first_segment, ++last_segment, 0,actual_segment_durations);
			}
			if (remove_file) 
			{
				sprintf(remove_filename,"%s%s-%u.ts",options.url_prefix,options.output_prefix,first_segment - 1);
				remove(remove_filename);
			}
			sprintf(m_output_file_name,"%s%s-%u.ts",options.url_prefix,options.output_prefix,m_output_index ++);
			printf("%s%s-%u.ts\n",options.url_prefix,options.output_prefix,m_output_index);
			if (avio_open(&oc->pb, m_output_file_name, AVIO_FLAG_WRITE) < 0)
			{
				printf("不能打开文件'%s'\n", m_output_file_name);
				break;
			}

			// Write a new header at the start of each file
			if (avformat_write_header(oc, NULL))
			{
				printf("文件头再次打不开\n");
				exit(1);
			}
			prev_segment_time = segment_time;
		}
		int ret =av_interleaved_write_frame(oc,&packet);
		if (ret < 0)
		{
			printf("警告：不能按帧写入流");
		}
		else if(ret > 0)
		{
			printf("结束了\n");
			av_free_packet(&packet);
			break;
		}
		av_free_packet(&packet);
	}while(!decode_done);

	/*---完成输出文件(写尾部)---*/
	uinit_mux();

	if (NUM_SEGMENTS && (int)(last_segment - first_segment) >= NUM_SEGMENTS - 1)
	{
		remove_file = 1;
		first_segment++;
	}
	else remove_file = 0;

	if (write_index) 
		write_index_file(first_segment, ++last_segment, 1, actual_segment_durations);

	if (remove_file)
	{
		sprintf(remove_filename,"%s%s-%u.ts",options.url_prefix,options.output_prefix,first_segment - 1);
		remove(remove_filename);
	}
	return;
}

int main(int argc,char **argv)
{
	av_register_all();
	avformat_network_init();
	//完成输入信息
	init_input(argc,argv);

	//初始化解码复用器
	init_demux(options.input_file,&ic);
	
	//开始切片
	go();
}