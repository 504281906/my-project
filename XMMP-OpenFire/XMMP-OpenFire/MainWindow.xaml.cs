using agsXMPP;
using agsXMPP.protocol.client;
using agsXMPP.Xml.Dom;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Security;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using XMMP_OpenFire.ViewModel;

namespace XMMP_OpenFire
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        
        public MainWindowViewModel viewModel;
        public MainWindow()
        {
            InitializeComponent();
            viewModel = new MainWindowViewModel();
            DataContext = viewModel;
        }

        private void btnLogin_Click(object sender, RoutedEventArgs e)
        {
            if (viewModel != null)
                viewModel.LoginXmpp();
        }

        private void btnSend_Click(object sender, RoutedEventArgs e)
        {
            if (viewModel != null)
                viewModel.SendMsg();
        }
    }
}
