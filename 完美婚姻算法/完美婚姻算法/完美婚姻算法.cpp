#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int n,i;  //n对单身男女
int a[1111][1314]; //女士i对男士j的好感排名
int b[1111][1314]; //男士i对女士j的好感排名
int A[1111][1314];  //女士i的最爱排名
int B[1111][1314];  //男士i的最爱排名
int marryA[1111];  //女士i是否订婚
int marryB[1111];  //男士i是否订婚
int firstA[1111]; //秉承女士优先的中华优良传统，选择最优女士算法，让女士优先选择。
//此代码三观正常，绝不可能出现同性相爱的情景，保证男女配对成功~┑(￣Д ￣)┍（手动微笑）- -！
//
void main()
{
	memset(marryA,0,sizeof(marryA));
	memset(marryB,0,sizeof(marryB));
	cout<<"请输入配对男女对数:";
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cout<<"请输入女士"<<i<<"的好感排名"<<endl;
		firstA[i]=1; //当然女士梦想中的一定是第一位白马王子，但是...
		for (int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			A[i][a[i][j]]=j;
		}
	}
	for (i=1;i<=n;i++)
	{
		cout<<"请输入男士"<<i<<"的好感排名"<<endl;
		for (int j=1;j<=n;j++)
		{
			cin>>b[i][j];
			B[i][b[i][j]]=j;
		}
	}
	int dog=n; //剩余单身狗的数量对
	i=1;//第i位女士的选择
	while (dog>0)
	{
		if (marryA[i])  //我们的女士i有主了，哼╭(╯^╰)╮
		{
			i++;
			continue;
		}
		if (i>n) 
		{
			cout<<"什么鬼！"<<endl;
			break;
		}
		if (!marryB[A[i][firstA[i]]])  //女士i看上的王子还没有订婚！！！赶紧抢过来！！！
		{
			marryB[A[i][firstA[i]]]=i;
			marryA[i]=A[i][firstA[i]];
			firstA[i]++;
			i++;
			dog--;     
			continue;
		}
		else{
			int BB = A[i][firstA[i]]; //女士i看重的男士BB
			int B_Girl = marryB[BB]; //BB的现任女友
			if (b[BB][B_Girl]<b[BB][i]) //这里是排名值，如果BB更爱他的现任女友，哼哼...
			{
				firstA[i]++; //我们的女士i只能去找下一位心中的白马王子了- -！
				continue;
			}
			else //否则就要移情别恋了...~~~~(>_<)~~~~
			{
				marryB[BB]=i;
				marryA[i]=BB;
				i=B_Girl; //可怜的B_Girl只能找下一任备胎填补心zhong的空白了
				marryA[i]=0; //单身万岁！
				continue;
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		cout<<"女士"<<i<<"的白马王子是："<<marryA[i]<<endl;
	}
	cout<<"最后愿天下有情人终成眷属！Thx"<<endl;
	system("pause");
}