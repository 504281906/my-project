#pragma once


// zhuce �Ի���

class zhuce : public CDialog
{
	DECLARE_DYNAMIC(zhuce)

public:
	zhuce(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~zhuce();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
