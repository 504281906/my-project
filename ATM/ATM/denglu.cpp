// denglu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ATM.h"
#include "denglu.h"
#include "zz.h"
#include "qukuan.h"//ȡǮ
#include "in.h"//��Ǯ
#include "zhuanzhang.h"
// denglu �Ի���

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


// denglu ��Ϣ�������

void denglu::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	long s=zz::ye[zz::d];
	CString s1;
	s1.Format(_T("�������Ϊ��%ld\n"),s);
	AfxMessageBox(s1);
}

void denglu::OnBnClickedButton4()
{
	qukuan Dlg3;
	Dlg3.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void denglu::OnBnClickedButton2()
{
	in Dlg4;
	Dlg4.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void denglu::OnBnClickedButton5()
{
	zhuanzhang Dlg5;
	Dlg5.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void denglu::OnBnClickedButton6()
{
	OnOK();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
