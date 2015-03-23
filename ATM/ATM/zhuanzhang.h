#pragma once


// zhuanzhang 对话框

class zhuanzhang : public CDialog
{
	DECLARE_DYNAMIC(zhuanzhang)

public:
	zhuanzhang(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~zhuanzhang();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString zh1;
	long je;
	afx_msg void OnBnClickedOk();
};
