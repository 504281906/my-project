// Button.cpp : implementation file
//

#include "stdafx.h"
#include "±í°×ÉñÆ÷By Modiz.h"
#include "Button.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Button

Button::Button()
{
}

Button::~Button()
{
}


BEGIN_MESSAGE_MAP(Button, CButton)
	//{{AFX_MSG_MAP(Button)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Button message handlers

void Button::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect ptrRect;
	GetParent()->GetClientRect(&ptrRect);
	CRect myRect;
	this->GetWindowRect(&myRect);
	CRect newRect;
	newRect.left=rand()%(ptrRect.Width()-myRect.Width()+5);
	newRect.top=rand()%(ptrRect.Height()-myRect.Height()+5);
	newRect.right=newRect.left+myRect.Width();
	newRect.bottom=newRect.top+myRect.Height();
	if (newRect.right+myRect.Width()+5>ptrRect.right)
	{
		newRect.left-=myRect.Width();
		newRect.right-=myRect.Width();
	}
	if (newRect.bottom+myRect.Height()+30>ptrRect.bottom)
	{
		newRect.bottom-=myRect.Height();
		newRect.top-=myRect.Height();
	}
	this->MoveWindow(&newRect,true);
	CButton::OnMouseMove(nFlags, point);
}