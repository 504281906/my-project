using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections;
namespace 五行八卦阵
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    
    public partial class MainWindow : Window
    {
        string[] ss = new string[7]{"缺德","缺心眼","缺钱","缺氧","缺颜","啥都不缺","缺钙"};
        string[] s1 = new string[8] { "乾", "坤", "震", "巽", "坎", "离", "艮", "兑" };
        int[] ans = new int[7];
        int[] ans1 = new int[8];
        int sum = 0;
        public void gorand() {
            Random ran = new Random(unchecked((int)DateTime.Now.Ticks));
            int[] a = new int[7]{0,1,2,3,4,5,6};
            int l=6;
            for (int i = 0; i < 7; i++) {
                int k = ran.Next(0, l);
                ans[i] = a[k];
                a[k] = a[l];
                l--;
            }
        }
        public void gorand1()
        {
            Random ran1 = new Random(unchecked((int)DateTime.Now.Ticks));
            int[] a = new int[8] { 0, 1, 2, 3, 4, 5, 6 ,7};
            int l = 7;
            for (int i = 0; i < 8; i++)
            {
                int k = ran1.Next(0, l);
                ans1[i] = a[k];
                a[k] = a[l];
                l--;
            }
        }
        void CC(bool f) {
            sum++;
            b1.IsEnabled = f;
            b2.IsEnabled = f;
            b3.IsEnabled = f;
            b4.IsEnabled = f;
            b5.IsEnabled = f;
            b6.IsEnabled = f;
            b7.IsEnabled = f;
            b8.IsEnabled = f;
        }
        public MainWindow()
        {
            //Uri iconUri = new Uri("C:\\Users\\modiz\\Documents\\Visual Studio 2012\\Projects\\五行八卦阵\\五行八卦阵\\go.ico", UriKind.RelativeOrAbsolute);
            //this.Icon = BitmapFrame.Create(iconUri);
            InitializeComponent();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            CC(false);
            b2.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
        }

        private void Button_Click2(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b1.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b2.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b1.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click_7(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b2.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b1.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b2.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b1.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click_6(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b2.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b1.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click_5(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b2.Content = ss[ans[0]];
            b3.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b1.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            ((Button)sender).Content = "缺爱";
            gorand();
            b2.Content = ss[ans[0]];
            b1.Content = ss[ans[1]];
            b4.Content = ss[ans[2]];
            b5.Content = ss[ans[3]];
            b6.Content = ss[ans[4]];
            b7.Content = ss[ans[5]];
            b8.Content = ss[ans[6]];
            CC(false);
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            //InitializeComponent();
            CC(true);
            gorand1();
            b1.Content = s1[ans1[7]];
            b2.Content = s1[ans1[0]];
            b3.Content = s1[ans1[1]];
            b4.Content = s1[ans1[2]];
            b5.Content = s1[ans1[3]];
            b6.Content = s1[ans1[4]];
            b7.Content = s1[ans1[5]];
            b8.Content = s1[ans1[6]];
            if (sum == 10) MessageBox.Show("看来您老命中缺爱啊！");
            if (sum == 20) MessageBox.Show("您居然不相信命运的安排？");
            if (sum == 30) MessageBox.Show("您居然还不信邪？");
            if (sum == 40) MessageBox.Show("好想你的眉毛");
            if (sum == 50) MessageBox.Show("看来只有我来陪你了...");
        }
    }
}
