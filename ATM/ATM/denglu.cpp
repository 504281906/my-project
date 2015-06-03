// denglu.cpp : 实现文件
//

#include "stdafx.h"
#include "ATM.h"
#include "denglu.h"
#include "zz.h"
#include "qukuan.h"//取钱
#include "in.h"//存钱
#include "zhuanzhang.h"
// denglu 对话框

IMPLEMENT_DYNAMIC(denglu, CDialog)

denglu::denglu(CWnd* pParent /*=NULL*/)
	: CDialog(denglu::IDD, pParent)
{

}

denglu::~denglu()
{
}

void denglu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(denglu, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &denglu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &denglu::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &denglu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &denglu::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &denglu::OnBnClickedButton6)
END_MESSAGE_MAP()


// denglu 消息处理程序

void denglu::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	long s=zz::ye[zz::d];
	CString s1;
	s1.Format(_T("您的余额为：%ld\n"),s);
	AfxMessageBox(s1);
}

void denglu::OnBnClickedButton4()
{
	qukuan Dlg3;
	Dlg3.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

void denglu::OnBnClickedButton2()
{
	in Dlg4;
	Dlg4.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

void denglu::OnBnClickedButton5()
{
	zhuanzhang Dlg5;
	Dlg5.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

void denglu::OnBnClickedButton6()
{
	OnOK();
	// TODO: 在此添加控件通知处理程序代码
}
