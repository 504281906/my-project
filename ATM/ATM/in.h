#pragma once


// in �Ի���

class in : public CDialog
{
	DECLARE_DYNAMIC(in)

public:
	in(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~in();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	long cunkuan;
};
