#include <string.h> 
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <math.h>

using namespace std;

extern "C"
{
#include "libavformat/avformat.h"
#include "libavformat/avio.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libavutil/avutil.h"
#include "libavutil/mathematics.h"
#include "libswresample/swresample.h"
#include "libavutil/opt.h"
#include "libavutil/channel_layout.h"
#include "libavutil/samplefmt.h"
#include "libavdevice/avdevice.h"  //����ͷ����
#include "libavfilter/avfilter.h"
#include "libavutil/error.h"
#include "libavutil/mathematics.h"  
#include "libavutil/time.h"  
#include "libavutil/fifo.h"
#include "libavutil/audio_fifo.h"   //����������Ƭʱ���ز���������Ƶ�õ�
#include "inttypes.h"
#include "stdint.h"
#include "getopt.h"
};

#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"avdevice.lib")
#pragma comment(lib,"avfilter.lib")
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"postproc.lib")
#pragma comment(lib,"swresample.lib")
#pragma comment(lib,"swscale.lib")

#define NUM_SEGMENTS        50
#define AUDIO_ID            0    //packet �е�ID ������ȼ�����Ƶ pocket ����Ƶ�� 0  ��Ƶ��1�������෴(Ӱ��add_out_stream˳��)
#define VIDEO_ID            1

struct options_t {
    const char *input_file;
    long segment_duration;
    const char *output_prefix;
    const char *m3u8_file;
    char *tmp_m3u8_file;
    const char *url_prefix;
    long num_segments;
};

struct options_t options;