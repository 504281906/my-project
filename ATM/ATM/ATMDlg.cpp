// ATMDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CATMDlg 对话框




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


// CATMDlg 消息处理程序

BOOL CATMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CATMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CATMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CATMDlg::OnBnClickedButton2()
{
	zhuce Dlg;
	Dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
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
			MessageBox(_T("密码错误或用户名不存在"),_T("对不起！"),MB_OK);
		else 
		{
			zz::d=f;
			MessageBox(_T("您好,登陆成功"),_T("恭喜您"));
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
		MessageBox(_T("密码错误或用户名不存在"),_T("对不起！"),MB_OK);
	else 
	{
		zz::d=f;
		MessageBox(_T("您好,登陆成功"),_T("恭喜您"));
		denglu Dlg1;
		Dlg1.DoModal();
	}
	// TODO: 在此添加控件通知处理程序代码
}
