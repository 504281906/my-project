// ±í°×ÉñÆ÷By ModizDlg.h : header file
//

#if !defined(AFX_BYMODIZDLG_H__A917E59C_9D36_4A7C_8F79_637F3CCFCAE6__INCLUDED_)
#define AFX_BYMODIZDLG_H__A917E59C_9D36_4A7C_8F79_637F3CCFCAE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include <shellapi.h>

/////////////////////////////////////////////////////////////////////////////
// CByModizDlg dialog
#include "Button.h"
class CByModizDlg : public CDialog
{
// Construction
public:
	CByModizDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CByModizDlg)
	enum { IDD = IDD_BYMODIZ_DIALOG };
	Button	m_btn;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CByModizDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CByModizDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnNO();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYMODIZDLG_H__A917E59C_9D36_4A7C_8F79_637F3CCFCAE6__INCLUDED_)
