#pragma once
// zz �Ի���

class zz : public CDialog
{
	DECLARE_DYNAMIC(zz)

public:
	zz(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~zz();
public:
	static int d;//��ǰ
	static int x;//���
	static long zh[200];//�˺�
	static long mima[200];//����
	static char mz[200][20];//����
	static long ye[200];//���
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
