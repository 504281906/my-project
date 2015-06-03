// in.cpp : 实现文件
//

#include "stdafx.h"
#include "ATM.h"
#include "in.h"
#include "zz.h"
#include <fstream>
using namespace std;
// in 对话框

IMPLEMENT_DYNAMIC(in, CDialog)

in::in(CWnd* pParent /*=NULL*/)
	: CDialog(in::IDD, pParent)
	, cunkuan(0)
{

}

in::~in()
{
}

void in::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cunkuan);
}


BEGIN_MESSAGE_MAP(in, CDialog)
	ON_BN_CLICKED(IDOK, &in::OnBnClickedOk)
END_MESSAGE_MAP()


// in 消息处理程序

void in::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (cunkuan!=0 && cunkuan>0)
	{
		zz::ye[zz::d]+=cunkuan;
		ofstream f;
		f.open("t.txt");
		f<<zz::x<<endl;
		for (int i=1;i<=zz::x;i++)
			f<<zz::zh[i]<<" "<<zz::mima[i]<<" "<<zz::ye[i]<<" "<<zz::mz[i]<<endl;
		MessageBox(_T("存入成功"));
		OnOK();
	}
	else 
		MessageBox(_T("金额必须大于零"));
	// TODO: 在此添加控件通知处理程序代码
}
