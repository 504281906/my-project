using agsXMPP;
using agsXMPP.protocol.client;
using agsXMPP.protocol.iq.disco;
using agsXMPP.Xml.Dom;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Windows;

namespace XMMP_OpenFire
{
    public class IMXmpp
    {
        private XmppClientConnection XmppCon;
        private bool bLogin;    //是否已经登陆
        private Action<bool, Exception> callBackXmpp;
        private Action<Message, Exception> callBackMsg;

        public void InitXmpp()
        {
            XmppCon = new XmppClientConnection();

            XmppCon.SocketConnectionType = agsXMPP.net.SocketConnectionType.Direct;

            XmppCon.OnLogin += new ObjectHandler(XmppCon_OnLogin);
            XmppCon.OnClose += new ObjectHandler(XmppCon_OnClose);
            XmppCon.OnError += new ErrorHandler(XmppCon_OnError);
            XmppCon.OnPresence += new agsXMPP.protocol.client.PresenceHandler(XmppCon_OnPresence);
            XmppCon.OnMessage += new agsXMPP.protocol.client.MessageHandler(XmppCon_OnMessage);
            XmppCon.OnAuthError += new XmppElementHandler(XmppCon_OnAuthError);
            XmppCon.OnSocketError += new ErrorHandler(XmppCon_OnSocketError);
            XmppCon.ClientSocket.OnValidateCertificate += new System.Net.Security.RemoteCertificateValidationCallback(ClientSocket_OnValidateCertificate);

            XmppCon.OnXmppConnectionStateChanged += new XmppConnectionStateHandler(XmppCon_OnXmppConnectionStateChanged);
        }

        /// <summary>
        /// bRegisterAccount = false    登陆
        /// bRegisterAccount = true     注册
        /// </summary>
        /// <param name="bRegisterAccount"></param>
        public void Login(string userName,string passWord, Action<bool, Exception> callBack)
        {
            callBackXmpp = callBack;
            Jid jid = new Jid(userName + "@192.168.112.157");
            XmppCon.Server = jid.Server;
            XmppCon.Username = jid.User;
            XmppCon.Password = passWord;
            XmppCon.Resource = userName;
            XmppCon.Priority = 10;
            XmppCon.Port = int.Parse("5223");
            XmppCon.UseSSL = true;
            XmppCon.AutoResolveConnectServer = true;
            XmppCon.UseCompression = false;
            XmppCon.RegisterAccount = false;

            XmppCon.EnableCapabilities = true;
            XmppCon.ClientVersion = "1.0";
            XmppCon.Capabilities.Node = "http://www.ag-software.de/miniclient/caps";

            XmppCon.DiscoInfo.AddIdentity(new DiscoIdentity("pc", "Modiz", "client"));
            XmppCon.DiscoInfo.AddFeature(new DiscoFeature(agsXMPP.Uri.DISCO_INFO));
            XmppCon.DiscoInfo.AddFeature(new DiscoFeature(agsXMPP.Uri.DISCO_ITEMS));
            XmppCon.DiscoInfo.AddFeature(new DiscoFeature(agsXMPP.Uri.MUC));
            XmppCon.Open();
        }

        /// <summary>
        /// 连接状态改变事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="state"></param>
        private void XmppCon_OnXmppConnectionStateChanged(object sender, XmppConnectionState state)
        {
            if (state == XmppConnectionState.Connected)
            {
                bLogin = true;
                callBackXmpp(bLogin, null);
            }
        }

        /// <summary>
        /// 确定是否接受指定证书进行身份验证
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="certificate"></param>
        /// <param name="chain"></param>
        /// <param name="sslPolicyErrors"></param>
        /// <returns></returns>
        private bool ClientSocket_OnValidateCertificate(object sender, X509Certificate certificate, X509Chain chain, SslPolicyErrors sslPolicyErrors)
        {
            return true;
        }

        /// <summary>
        /// Socket连接错误
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="ex"></param>
        private void XmppCon_OnSocketError(object sender, Exception ex)
        {
            MessageBox.Show("Socket 连接错误:\r\n" + ex.Message + "\r\n" + ex.InnerException);
        }

        /// <summary>
        /// 认证错误事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void XmppCon_OnAuthError(object sender, Element e)
        {
            MessageBox.Show("认证错误");
        }

        /// <summary>
        /// 连接服务器报错
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="ex"></param>
        private void XmppCon_OnError(object sender, Exception ex)
        {
            MessageBox.Show("连接错误事件,无法登陆到服务器:\r\n" + ex.Message + "\r\n" + ex.InnerException);
        }

        /// <summary>
        /// 关闭连接
        /// </summary>
        /// <param name="sender"></param>
        private void XmppCon_OnClose(object sender)
        {
            bLogin = false;
            callBackXmpp(bLogin, null);
        }

        /// <summary>
        /// 登录成功
        /// </summary>
        /// <param name="sender"></param>
        private void XmppCon_OnLogin(object sender)
        {
            bLogin = true;
            callBackXmpp(bLogin, null);
        }

        /// <summary>
        /// 发送消息
        /// </summary>
        /// <param name="sendName"></param>
        /// <param name="sendMsg"></param>
        internal void SendMsg(string sendName, string sendMsg)
        {
            Jid jid = new Jid(sendName + "@127.0.0.1");
            Message mes = new Message(jid, MessageType.chat, sendMsg);
            XmppCon.Send(mes);
        }

        /// <summary>
        /// 接收消息回调
        /// </summary>
        /// <param name="v"></param>
        internal void receiveMsg(Action<Message, Exception> callBack)
        {
            callBackMsg = callBack;
        }

        /// <summary>
        /// 接收消息
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="msg"></param>
        private void XmppCon_OnMessage(object sender, Message msg)
        {
            if (msg.Type != MessageType.error)
            {
                if (msg.Body != null)
                {
                    //MessageBox.Show("收到信息:\r\n" + msg.Body);
                    callBackMsg(msg, null);
                }
            }
        }

        /// <summary>
        /// 接收并通过用户请求
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="pres"></param>
        private void XmppCon_OnPresence(object sender, Presence pres)
        {
            if (pres.Type == PresenceType.subscribe)
            {
                PresenceManager pm = new PresenceManager(XmppCon);
                pm.ApproveSubscriptionRequest(pres.From);
            }
        }
    }
}
