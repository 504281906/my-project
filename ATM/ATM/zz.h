#pragma once
// zz 对话框

class zz : public CDialog
{
	DECLARE_DYNAMIC(zz)

public:
	zz(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~zz();
public:
	static int d;//当前
	static int x;//编号
	static long zh[200];//账号
	static long mima[200];//密码
	static char mz[200][20];//名字
	static long ye[200];//金额
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
