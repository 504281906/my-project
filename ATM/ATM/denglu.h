#pragma once


// denglu 对话框

class denglu : public CDialog
{
	DECLARE_DYNAMIC(denglu)

public:
	denglu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~denglu();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
