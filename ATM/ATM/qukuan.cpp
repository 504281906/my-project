// qukuan.cpp : 实现文件
//

#include "stdafx.h"
#include "ATM.h"
#include "qukuan.h"
#include "zz.h"
#include <fstream>
using namespace std;
// qukuan 对话框

IMPLEMENT_DYNAMIC(qukuan, CDialog)

qukuan::qukuan(CWnd* pParent /*=NULL*/)
	: CDialog(qukuan::IDD, pParent)
	, qk(0)
{

}

qukuan::~qukuan()
{
}

void qukuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, qk);
}


BEGIN_MESSAGE_MAP(qukuan, CDialog)
	ON_BN_CLICKED(IDOK, &qukuan::OnBnClickedOk)
END_MESSAGE_MAP()


// qukuan 消息处理程序

void qukuan::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (qk>0)
	{
		if (zz::ye[zz::d]>=qk)
	{
		zz::ye[zz::d]-=qk;
		ofstream f;
		f.open("t.txt");
		f<<zz::x<<endl;
		for (int i=1;i<=zz::x;i++)
			f<<zz::zh[i]<<" "<<zz::mima[i]<<" "<<zz::ye[i]<<" "<<zz::mz[i]<<endl;
		MessageBox(_T("取款成功"));
		OnOK();
	}
	else 
	{
		MessageBox(_T("账户余额不足"));
	}
	}
	else 
	{
		MessageBox(_T("取款金额必须大于零"));
	}
	// TODO: 在此添加控件通知处理程序代码
}
