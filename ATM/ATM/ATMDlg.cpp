// ATMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ATM.h"
#include "ATMDlg.h"
#include "zhuce.h"
#include "denglu.h"
#include "zz.h"
#include <fstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CATMDlg �Ի���




CATMDlg::CATMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CATMDlg::IDD, pParent)
	, yhm(_T(""))
	, mm(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CATMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBOBOXEX1, yhm);
	DDX_Text(pDX, IDC_EDIT1, mm);
}

BEGIN_MESSAGE_MAP(CATMDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON2, &CATMDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CATMDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CATMDlg ��Ϣ�������

BOOL CATMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	ifstream ff;
	ff.open("t.txt");
	ff>>zz::x;
	for (int i=1;i<=zz::x;i++)
		ff>>zz::zh[i]>>zz::mima[i]>>zz::ye[i]>>zz::mz[i];
	ff.close();
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CATMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CATMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CATMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CATMDlg::OnBnClickedButton2()
{
	zhuce Dlg;
	Dlg.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
BOOL CATMDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN)
	{
		UpdateData(TRUE);
		int f=0,i;
		long s=_ttoi(yhm);
		long s1=_ttoi(mm);
		for ( i=1;i<=zz::x;i++)
		{
			if (s==zz::zh[i] && s1==zz::mima[i])
			{
				f=i;
				break;
			}
		}
		if (f==0)
			MessageBox(_T("���������û���������"),_T("�Բ���"),MB_OK);
		else 
		{
			zz::d=f;
			MessageBox(_T("����,��½�ɹ�"),_T("��ϲ��"));
			denglu Dlg1;
			Dlg1.DoModal();
		}
	}
	return false;
}

void CATMDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int f=0,i;
	long s=_ttoi(yhm);
	long s1=_ttoi(mm);
	for ( i=1;i<=zz::x;i++)
	{
		if (s==zz::zh[i] && s1==zz::mima[i])
		{
			f=i;
			break;
		}
	}
	if (f==0)
		MessageBox(_T("���������û���������"),_T("�Բ���"),MB_OK);
	else 
	{
		zz::d=f;
		MessageBox(_T("����,��½�ɹ�"),_T("��ϲ��"));
		denglu Dlg1;
		Dlg1.DoModal();
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
