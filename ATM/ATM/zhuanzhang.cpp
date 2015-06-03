// zhuanzhang.cpp : 实现文件
//

#include "stdafx.h"
#include "ATM.h"
#include "zhuanzhang.h"
#include "zz.h"
#include <fstream>
using namespace std;
// zhuanzhang 对话框

IMPLEMENT_DYNAMIC(zhuanzhang, CDialog)

zhuanzhang::zhuanzhang(CWnd* pParent /*=NULL*/)
	: CDialog(zhuanzhang::IDD, pParent)
	, zh1(_T(""))
	, je(0)
{

}

zhuanzhang::~zhuanzhang()
{
}

void zhuanzhang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, zh1);
	DDX_Text(pDX, IDC_EDIT3, je);
}


BEGIN_MESSAGE_MAP(zhuanzhang, CDialog)
	ON_BN_CLICKED(IDOK, &zhuanzhang::OnBnClickedOk)
END_MESSAGE_MAP()


// zhuanzhang 消息处理程序

void zhuanzhang::OnBnClickedOk()
{
	UpdateData(TRUE);
	int f=0;
	long s;
	s=_ttoi(zh1);
	for (int i=1;i<=zz::x;i++)
	{
		if (s==zz::zh[i])
		{f=i;break;}
	}
	if (f && f!=zz::d)
	{
		if (je>=0 && zz::ye[zz::d]>=je)
		{
			zz::ye[zz::d]-=je;
			zz::ye[f]+=je;
			ofstream f;
		f.open("t.txt");
		f<<zz::x<<endl;
		for (int i=1;i<=zz::x;i++)
			f<<zz::zh[i]<<" "<<zz::mima[i]<<" "<<zz::ye[i]<<" "<<zz::mz[i]<<endl;
			MessageBox(_T("转账成功"));
			OnOK();
		}
		else 
			MessageBox(_T("账户余额不足"));
	}
	else MessageBox(_T("账户不存在"));
	// TODO: 在此添加控件通知处理程序代码
}
