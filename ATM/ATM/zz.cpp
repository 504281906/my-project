#include "stdafx.h"
#include "ATM.h"
#include "zz.h"
#include <fstream>
using namespace std;

// zz 对话框

IMPLEMENT_DYNAMIC(zz, CDialog)

zz::zz(CWnd* pParent /*=NULL*/)
	: CDialog(zz::IDD, pParent)
{
}

zz::~zz()
{
}

void zz::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
long zz::zh[200];
int zz::x;
char zz::mz[200][20];
long zz::ye[200];
long zz::mima[200];
int zz::d=0;
void main()
{
	
}
BEGIN_MESSAGE_MAP(zz, CDialog)
END_MESSAGE_MAP()


// zz 消息处理程序
