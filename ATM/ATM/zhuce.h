#pragma once


// zhuce 对话框

class zhuce : public CDialog
{
	DECLARE_DYNAMIC(zhuce)

public:
	zhuce(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~zhuce();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString zhm;
	CString mm1;
	CString mm2;
	CString xm;
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL PreTranslateMessage();
};
