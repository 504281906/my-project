// qukuan.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ATM.h"
#include "qukuan.h"
#include "zz.h"
#include <fstream>
using namespace std;
// qukuan �Ի���

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


// qukuan ��Ϣ�������

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
		MessageBox(_T("ȡ��ɹ�"));
		OnOK();
	}
	else 
	{
		MessageBox(_T("�˻�����"));
	}
	}
	else 
	{
		MessageBox(_T("ȡ������������"));
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
