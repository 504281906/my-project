#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,i;  //n�Ե�����Ů
int a[1111][1314]; //Ůʿi����ʿj�ĺø�����
int b[1111][1314]; //��ʿi��Ůʿj�ĺø�����
int A[1111][1314];  //Ůʿi�������
int B[1111][1314];  //��ʿi�������
int marryA[1111];  //Ůʿi�Ƿ񶩻�
int marryB[1111];  //��ʿi�Ƿ񶩻�
int firstA[1111]; //����Ůʿ���ȵ��л�������ͳ��ѡ������Ůʿ�㷨����Ůʿ����ѡ��
//�˴��������������������ܳ���ͬ���మ���龰����֤��Ů��Գɹ�~��(���� ��)�����ֶ�΢Ц��- -��
//
void main()
{
	memset(marryA,0,sizeof(marryA));
	memset(marryB,0,sizeof(marryB));
	cout<<"�����������Ů����:";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cout<<"������Ůʿ"<<i<<"�ĺø�����"<<endl;
		firstA[i]=1; //��ȻŮʿ�����е�һ���ǵ�һλ�������ӣ�����...
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			A[i][a[i][j]]=j;
		}
	}
	for (i=1;i<=n;i++)
	{
		cout<<"��������ʿ"<<i<<"�ĺø�����"<<endl;
		for (int j=1;j<=n;j++)
		{
			cin>>b[i][j];
			B[i][b[i][j]]=j;
		}
	}
	int dog=n; //ʣ�൥����������
	i=1;//��iλŮʿ��ѡ��
	while (dog>0)
	{
		if (marryA[i])  //���ǵ�Ůʿi�����ˣ��ߨq(�s^�t)�r
		{
			i++;
			continue;
		}
		if (i>n) 
		{
			cout<<"ʲô��"<<endl;
			break;
		}
		if (!marryB[A[i][firstA[i]]])  //Ůʿi���ϵ����ӻ�û�ж��飡�����Ͻ�������������
		{
			marryB[A[i][firstA[i]]]=i;
			marryA[i]=A[i][firstA[i]];
			firstA[i]++;
			i++;
			dog--;     
			continue;
		}
		else{
			int BB = A[i][firstA[i]]; //Ůʿi���ص���ʿBB
			int B_Girl = marryB[BB]; //BB������Ů��
			if (b[BB][B_Girl]<b[BB][i]) //����������ֵ�����BB������������Ů�ѣ��ߺ�...
			{
				firstA[i]++; //���ǵ�Ůʿiֻ��ȥ����һλ���еİ���������- -��
				continue;
			}
			else //�����Ҫ���������...~~~~(>_<)~~~~
			{
				marryB[BB]=i;
				marryA[i]=BB;
				i=B_Girl; //������B_Girlֻ������һ�α�̥���zhong�Ŀհ���
				marryA[i]=0; //�������꣡
				continue;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		cout<<"Ůʿ"<<i<<"�İ��������ǣ�"<<marryA[i]<<endl;
	}
	cout<<"���Ը�����������ճɾ�����Thx"<<endl;
	system("pause");
}