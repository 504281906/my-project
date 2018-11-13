using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Threading;
using agsXMPP.protocol.client;

namespace XMMP_OpenFire.ViewModel
{
    public class msg
    {
        public string msgContent { get; set; }

        public string foreground { get; set; }
    }

    public class MainWindowViewModel : INotifyPropertyChanged
    {
        #region 数据绑定 通知变更
        public event PropertyChangedEventHandler PropertyChanged;
        private void RaisePropertyChanged(string propertyName)
        {
            if (PropertyChanged != null)
            {
                this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
        #endregion

        #region 数据参数
        private bool _isLogin = false;
        /// <summary>
        /// 是否登录
        /// </summary>
        public bool IsLogin
        {
            get
            {
                return _isLogin;
            }
            set
            {
                _isLogin = value;
                RaisePropertyChanged("IsLogin");
            }
        }

        private string _userName = "modiz";

        /// <summary>
        /// 账户
        /// </summary>
        public string userName
        {
            get
            {
                return _userName;
            }
            set
            {
                _userName = value;
                RaisePropertyChanged("userName");
            }
        }

        private string _passWord = "123456";
        /// <summary>
        /// 密码
        /// </summary>
        public string passWord
        {
            get
            {
                return _passWord;
            }
            set
            {
                _passWord = value;
                RaisePropertyChanged("passWord");
            }
        }

        private string _sendName;
        /// <summary>
        /// 接收方名称
        /// </summary>
        public string sendName
        {
            get
            {
                return _sendName;
            }
            set
            {
                _sendName = value;
                RaisePropertyChanged("sendName");
            }
        }

        private string _sendMsg;
        /// <summary>
        /// 发送内容
        /// </summary>
        public string sendMsg
        {
            get
            {
                return _sendMsg;
            }
            set
            {
                _sendMsg = value;
                RaisePropertyChanged("sendMsg");
            }
        }

        private ObservableCollection<msg> _msgList = new ObservableCollection<msg>();
        /// <summary>
        /// 消息列表
        /// </summary>
        public ObservableCollection<msg> msgList
        {
            get
            {
                return _msgList;
            }
            set
            {
                if (_msgList != value)
                {
                    _msgList = value;
                    RaisePropertyChanged("msgList");
                }
            }
        }

        #endregion

        #region XMPP
        private IMXmpp imXmpp;
        #endregion

        #region 构造函数
        public MainWindowViewModel()
        {
            imXmpp = new IMXmpp();
            imXmpp.InitXmpp();
            msgList = new ObservableCollection<msg>();
        }
        #endregion

        #region
        public void LoginXmpp()
        {
            imXmpp.Login(userName,passWord,LoginCallBack());
        }

        private Action<bool, Exception> LoginCallBack()
        {
            return (isLogin, ex) => //回调
            {
                IsLogin = isLogin;
                if (IsLogin)
                    imXmpp.receiveMsg(ReceiVeMsgCallBack());
            };
        }

        private Action<Message, Exception> ReceiVeMsgCallBack()
        {
            return (msg1, ex) => //回调
            {

                if (msg1.Type != MessageType.error)
                {
                    if (msg1.Body != null)
                    {
                        msg ff = new msg();
                        ff.msgContent = msg1.From.User + ":" + msg1.Body;
                        ff.foreground = "#000000";
                        Application.Current.Dispatcher.Invoke((Action)delegate()
                        {
                            msgList.Add(ff);
                        });
                    }
                }
                
            };
        }

        public void SendMsg()
        {
            imXmpp.SendMsg(sendName, sendMsg);
            msg ff = new msg();
            ff.msgContent = "me:" + sendMsg;
            ff.foreground = "#FF0000";
            msgList.Add(ff);
        }
        #endregion

    }
}
