#pragma once


// qukuan �Ի���

class qukuan : public CDialog
{
	DECLARE_DYNAMIC(qukuan)

public:
	qukuan(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~qukuan();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long qk;
	afx_msg void OnBnClickedOk();
};
