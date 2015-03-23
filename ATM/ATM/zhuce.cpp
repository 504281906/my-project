// zhuce.cpp : 实现文件
//

#include "stdafx.h"
#include "ATM.h"
#include "zhuce.h"
#include "zz.h"
#include <fstream>
using namespace std;
// zhuce 对话框

IMPLEMENT_DYNAMIC(zhuce, CDialog)

zhuce::zhuce(CWnd* pParent /*=NULL*/)
	: CDialog(zhuce::IDD, pParent)
	, zhm(_T(""))
	, mm1(_T(""))
	, mm2(_T(""))
	, xm(_T(""))
{

}

zhuce::~zhuce()
{
}

void zhuce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, zhm);
	DDX_Text(pDX, IDC_EDIT2, mm1);
	DDX_Text(pDX, IDC_EDIT3, mm2);
	DDX_Text(pDX, IDC_EDIT4, xm);
}
BEGIN_MESSAGE_MAP(zhuce, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &zhuce::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &zhuce::OnBnClickedButton1)
END_MESSAGE_MAP()


// zhuce 消息处理程序

void zhuce::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

/*BOOL zhuce::PreTranslateMessage(MSG* pMsgg)
{
	if(pMsgg->message==WM_KEYDOWN && pMsgg->wParam==VK_RETURN)
	{
	UpdateData(TRUE);
	long s;
	int f=0;
	s=_ttoi(zhm);
	if (s==0) MessageBox(_T("账户名不能为空"),_T("对不起！"),MB_OK);
	else 
		if (xm.GetLength()==0) MessageBox(_T("姓名不能为空"),_T("对不起！"),MB_OK);
	for (int i=1;i<=zz::x;i++)
	{
		if (s==zz::zh[i])
		{
			MessageBox(_T("账户名已存在"),_T("对不起！"),MB_OK);
			f=1;
			break;
		}
	}
	if (!f && xm.GetLength()!=0)
	{
		if (mm1.GetLength()!=6)
			MessageBox(_T("密码只能是6位数字"),_T("对不起！"),MB_OK);
		else
		if (mm1==mm2)
		{
			zz::x=zz::x+1;
			zz::zh[zz::x]=s;
			//strncpy(zz::mz[zz::x],xm,sizeof(zz::mz[zz::x]));
			zz::ye[zz::x]=0;
			zz::mima[zz::x]=_ttoi(mm1);
			ofstream f;
			f.open("t.txt",ios::in);
			f<<zz::x<<endl;
			f.close();
			f.open("t.txt",ios::ate|ios::app);
			f<<zz::zh[zz::x]<<" "<<zz::mima[zz::x]<<" "<<zz::ye[zz::x]<<" "<<xm<<endl;
			f.close();
			MessageBox(_T("注册成功,您的卡上余额为0元"),_T("恭喜你！"),MB_OK);
			OnOK();
		}
		else
			MessageBox(_T("两次输入密码不一致"),_T("对不起！"),MB_OK);
	}
	}
	return false;
}*/
void zhuce::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	long s;
	int f=0;
	s=_ttoi(zhm);
	if (s==0) MessageBox(_T("账户名不能为空"),_T("对不起！"),MB_OK);
	else 
		if (xm.GetLength()==0) MessageBox(_T("姓名不能为空"),_T("对不起！"),MB_OK);
	for (int i=1;i<=zz::x;i++)
	{
		if (s==zz::zh[i])
		{
			MessageBox(_T("账户名已存在"),_T("对不起！"),MB_OK);
			f=1;
			break;
		}
	}
	if (!f && xm.GetLength()!=0)
	{
		if (mm1.GetLength()!=6)
			MessageBox(_T("密码只能是6位数字"),_T("对不起！"),MB_OK);
		else
		if (mm1==mm2)
		{
			zz::x=zz::x+1;
			zz::zh[zz::x]=s;
			//strncpy(zz::mz[zz::x],xm,sizeof(zz::mz[zz::x]));
			zz::ye[zz::x]=0;
			zz::mima[zz::x]=_ttoi(mm1);
			ofstream f;
			f.open("t.txt",ios::in);
			f<<zz::x<<endl;
			f.close();
			f.open("t.txt",ios::ate|ios::app);
			f<<zz::zh[zz::x]<<" "<<zz::mima[zz::x]<<" "<<zz::ye[zz::x]<<" "<<xm<<endl;
			f.close();
			MessageBox(_T("注册成功,您的卡上余额为0元"),_T("恭喜你！"),MB_OK);
			OnOK();
		}
		else
			MessageBox(_T("两次输入密码不一致"),_T("对不起！"),MB_OK);
	}
}
