// zhuce.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ATM.h"
#include "zhuce.h"
#include "zz.h"
#include <fstream>
using namespace std;
// zhuce �Ի���

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


// zhuce ��Ϣ�������

void zhuce::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	if (s==0) MessageBox(_T("�˻�������Ϊ��"),_T("�Բ���"),MB_OK);
	else 
		if (xm.GetLength()==0) MessageBox(_T("��������Ϊ��"),_T("�Բ���"),MB_OK);
	for (int i=1;i<=zz::x;i++)
	{
		if (s==zz::zh[i])
		{
			MessageBox(_T("�˻����Ѵ���"),_T("�Բ���"),MB_OK);
			f=1;
			break;
		}
	}
	if (!f && xm.GetLength()!=0)
	{
		if (mm1.GetLength()!=6)
			MessageBox(_T("����ֻ����6λ����"),_T("�Բ���"),MB_OK);
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
			MessageBox(_T("ע��ɹ�,���Ŀ������Ϊ0Ԫ"),_T("��ϲ�㣡"),MB_OK);
			OnOK();
		}
		else
			MessageBox(_T("�����������벻һ��"),_T("�Բ���"),MB_OK);
	}
	}
	return false;
}*/
void zhuce::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	long s;
	int f=0;
	s=_ttoi(zhm);
	if (s==0) MessageBox(_T("�˻�������Ϊ��"),_T("�Բ���"),MB_OK);
	else 
		if (xm.GetLength()==0) MessageBox(_T("��������Ϊ��"),_T("�Բ���"),MB_OK);
	for (int i=1;i<=zz::x;i++)
	{
		if (s==zz::zh[i])
		{
			MessageBox(_T("�˻����Ѵ���"),_T("�Բ���"),MB_OK);
			f=1;
			break;
		}
	}
	if (!f && xm.GetLength()!=0)
	{
		if (mm1.GetLength()!=6)
			MessageBox(_T("����ֻ����6λ����"),_T("�Բ���"),MB_OK);
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
			MessageBox(_T("ע��ɹ�,���Ŀ������Ϊ0Ԫ"),_T("��ϲ�㣡"),MB_OK);
			OnOK();
		}
		else
			MessageBox(_T("�����������벻һ��"),_T("�Բ���"),MB_OK);
	}
}
