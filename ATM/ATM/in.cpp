// in.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ATM.h"
#include "in.h"
#include "zz.h"
#include <fstream>
using namespace std;
// in �Ի���

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


// in ��Ϣ�������

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
		MessageBox(_T("����ɹ�"));
		OnOK();
	}
	else 
		MessageBox(_T("�����������"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
