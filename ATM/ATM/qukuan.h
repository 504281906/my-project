#pragma once


// qukuan 对话框

class qukuan : public CDialog
{
	DECLARE_DYNAMIC(qukuan)

public:
	qukuan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~qukuan();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long qk;
	afx_msg void OnBnClickedOk();
};
