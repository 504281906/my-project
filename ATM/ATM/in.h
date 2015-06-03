#pragma once


// in 对话框

class in : public CDialog
{
	DECLARE_DYNAMIC(in)

public:
	in(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~in();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	long cunkuan;
};
