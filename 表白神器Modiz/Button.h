#if !defined(AFX_BUTTON_H__5A03F8B0_5444_48F9_BFF0_2A514C796E14__INCLUDED_)
#define AFX_BUTTON_H__5A03F8B0_5444_48F9_BFF0_2A514C796E14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Button.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Button window

class Button : public CButton
{
// Construction
public:
	Button();

// Attributes
public:
	int cw,ch;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Button)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~Button();

	// Generated message map functions
protected:
	//{{AFX_MSG(Button)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//afx_msg void GetResourceHandle(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTON_H__5A03F8B0_5444_48F9_BFF0_2A514C796E14__INCLUDED_)
