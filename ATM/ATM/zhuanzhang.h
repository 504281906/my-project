#pragma once


// zhuanzhang �Ի���

class zhuanzhang : public CDialog
{
	DECLARE_DYNAMIC(zhuanzhang)

public:
	zhuanzhang(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~zhuanzhang();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString zh1;
	long je;
	afx_msg void OnBnClickedOk();
};
