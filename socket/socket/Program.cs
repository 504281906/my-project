using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;

namespace ConsoleApplication2
{
    #region socket封装
    public static class SocketTest
    {
        private static Encoding encode = Encoding.Default;
        /// <summary>
        /// 监听请求
        /// </summary>
        /// <param name="port"></param>
        public static void Listen(int port)
        {
            Socket listenSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            listenSocket.Bind(new IPEndPoint(IPAddress.Any, port));
            listenSocket.Listen(100);
            Console.WriteLine("Listen " + port + " ...");
            while (true)
            {
                Socket acceptSocket = listenSocket.Accept();
                string receiveData = Receive(acceptSocket, 5000); //5 seconds timeout.
                Console.WriteLine("Receive：" + receiveData);
                acceptSocket.Send(encode.GetBytes("ok"));
                DestroySocket(acceptSocket); //import
            }
        }
        /// <summary>
        /// 发送数据
        /// </summary>
        /// <param name="host"></param>
        /// <param name="port"></param>
        /// <param name="data"></param>
        /// <returns></returns>
        public static string Send(string host, int port, string data)
        {
            string result = string.Empty;
            Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            clientSocket.Connect(host, port);
            clientSocket.Send(encode.GetBytes(data));
            Console.WriteLine("Send：" + data);
            result = Receive(clientSocket, 5000 * 2); //5*2 seconds timeout.
            Console.WriteLine("Receive：" + result);
            DestroySocket(clientSocket);
            return result;
        }

        /// <summary>
        /// 发送数据
        /// </summary>
        /// <param name="host"></param>
        /// <param name="port"></param>
        /// <param name="data"></param>
        /// <returns></returns>
        public static string SendByte(Socket clientSocket, byte[] data)
        {
            string result = string.Empty;
            //Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            clientSocket.Send(data);
            Console.WriteLine("Send：" + data);
            //result = Receive(clientSocket, 5000 * 2); //5*2 seconds timeout.
            //Console.WriteLine("Receive：" + result);

            return result;
        }

        public static Socket BulidSocket(string host, int port)
        {
            string result = string.Empty;
            Socket clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            clientSocket.Connect(host, port);
            return clientSocket;
        }

        public static void DestroySocketYep(Socket clientSocket)
        {
            DestroySocket(clientSocket);
        }

        /// <summary>
        /// 接收数据
        /// </summary>
        /// <param name="socket"></param>
        /// <param name="timeout"></param>
        /// <returns></returns>
        private static string Receive(Socket socket, int timeout)
        {
            string result = string.Empty;
            socket.ReceiveTimeout = timeout;
            List<byte> data = new List<byte>();
            byte[] buffer = new byte[1024];
            int length = 0;
            try
            {
                while ((length = socket.Receive(buffer)) > 0)
                {
                    for (int j = 0; j < length; j++)
                    {
                        data.Add(buffer[j]);
                    }
                    if (length < buffer.Length)
                    {
                        break;
                    }
                }
            }
            catch { }
            if (data.Count > 0)
            {
                result = encode.GetString(data.ToArray(), 0, data.Count);
            }
            return result;
        }
        /// <summary>
        /// 销毁Socket对象
        /// </summary>
        /// <param name="socket"></param>
        private static void DestroySocket(Socket socket)
        {
            if (socket.Connected)
            {
                socket.Shutdown(SocketShutdown.Both);
            }
            socket.Close();
        }
    }

    /// <summary>
    /// 工具类：文件与二进制流间的转换
    /// </summary>
    class FileBinaryConvertHelper
    {
        /// <summary>
        /// 将文件转换为byte数组
        /// </summary>
        /// <param name="path">文件地址</param>
        /// <returns>转换后的byte数组</returns>
        public static byte[] File2Bytes(string path)
        {
            if (!File.Exists(path))
            {
                return new byte[0];
            }

            FileInfo fi = new FileInfo(path);
            byte[] buff = new byte[fi.Length];

            FileStream fs = fi.OpenRead();
            fs.Read(buff, 0, Convert.ToInt32(fs.Length));
            fs.Close();

            return buff;
        }

        /// <summary>
        /// 将byte数组转换为文件并保存到指定地址
        /// </summary>
        /// <param name="buff">byte数组</param>
        /// <param name="savepath">保存地址</param>
        public static void Bytes2File(byte[] buff, string savepath)
        {
            if (File.Exists(savepath))
            {
                File.Delete(savepath);
            }

            FileStream fs = new FileStream(savepath, FileMode.CreateNew);
            BinaryWriter bw = new BinaryWriter(fs);
            bw.Write(buff, 0, buff.Length);
            bw.Close();
            fs.Close();
        }
    }

    #endregion
    class Program
    {
        static void Main(string[] args)
        {
            byte[] b3 = new byte[] { 248, 255, 79, 0 };
            int k = BitConverter.ToInt32(b3,0);
            Socket socket = SocketTest.BulidSocket("192.168.112.225", 9102);
            byte[] leftbut = new byte[] { 30, 0, 0, 0, 0, 0, 0, 0 };
            byte[] rightbut = new byte[] { 30, 1, 0, 0, 0, 0, 0, 0 };
            byte[] mousemove = new byte[] { 30, 2, 0, 0, 8, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
            //SocketTest.SendByte("192.168.112.225", 9102, leftbut);
            //SocketTest.SendByte("192.168.112.225", 9102, rightbut);
            int jj = 0;
            //while (true)
            //{
            //    SocketTest.SendByte(socket, mousemove);
            //    SocketTest.SendByte(socket, mousemove);
            //    jj++;
            //    if (jj > 10000) break;
            //}
            //string str = "a.jpg|3456789";
            //byte[] b = System.Text.Encoding.Default.GetBytes(str);
            //string content = System.Text.Encoding.Default.GetString(b);
            //int index = content.IndexOf('|');
            //string FileName = content.Substring(0, index);
            //string FileSize = content.Substring(index + 1);
            string fileName = "a.mp4";
            byte[] b1 = new byte[] { 20, 1, 0, 0 };
            byte[] b2 = new byte[] { 20, 2, 0, 0};
            byte[] bytTemp = FileBinaryConvertHelper.File2Bytes(fileName);
            int pos = 0;
            var m = new List<byte>();
            int n = bytTemp.Count();
            string s = fileName + "|" + n.ToString();
            m.AddRange(b1);
            m.AddRange(BitConverter.GetBytes(s.Length));

            m.AddRange(System.Text.Encoding.Default.GetBytes(s));
            int pike = 1024*5*1024;
            while (pos < n)
            {
                m.AddRange(b2);
                if (n - pos >= pike)
                {
                    m.AddRange(BitConverter.GetBytes(pike));
                    for (int i = pos; i < pos+ pike; i++)
                        m.Add(bytTemp[i]);
                    pos += pike;
                }
                else
                {
                    m.AddRange(BitConverter.GetBytes(n - pos));
                    for (int i = pos; i < n; i++)
                        m.Add(bytTemp[i]);
                    break;
                }
            }
            
            //m.AddRange(b);
            //m.AddRange(bytTemp);
            var result = m.ToArray();
            byte[] ok = new byte[] { 20, 3, 0, 0 , 4, 0, 0, 0};
            m = new List<byte>();
            m.AddRange(result);
            m.AddRange(ok);
            m.AddRange(BitConverter.GetBytes(n));
            var result1 = m.ToArray();
            //var type = BitConverter.ToInt32(Quit,0);
            SocketTest.SendByte(socket, result1);
            //SocketTest.SendByte("192.168.112.225", 9102, ok);
            Console.Read();
            SocketTest.DestroySocketYep(socket);
        }

    }
}