#pragma once


// denglu �Ի���

class denglu : public CDialog
{
	DECLARE_DYNAMIC(denglu)

public:
	denglu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~denglu();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
