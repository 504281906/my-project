// 表白神器By Modiz.h : main header file for the 表白神器BY MODIZ application
//

#if !defined(AFX_BYMODIZ_H__E62EA667_EF7B_4FDA_8400_13030DA735CC__INCLUDED_)
#define AFX_BYMODIZ_H__E62EA667_EF7B_4FDA_8400_13030DA735CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"
#include "windows.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CByModizApp:
// See 表白神器By Modiz.cpp for the implementation of this class
//

class CByModizApp : public CWinApp
{
public:
	CByModizApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CByModizApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CByModizApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYMODIZ_H__E62EA667_EF7B_4FDA_8400_13030DA735CC__INCLUDED_)
