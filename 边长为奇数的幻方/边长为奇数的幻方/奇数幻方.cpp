#include<iostream>
#include<cstdio>
#include <fstream>
using namespace std;
int main(){
	int n;
	printf("请输入边长为奇数的N(输入0退出游戏)：");
	cin>>n;
	while(n!=0){
		//动态申请二维数组
		int **a;
		a=new int*[n+5];
		for (int i=0;i<n+5;i++)
			a[i]=new int[n+5];

		//初始化
		for (int i=0;i<n+5;i++)
			for (int j=0;j<n+5;j++)
				a[i][j]=0;

		int x=1;int y=(n+1)/2; //定义坐标
		int t=2; //定义计数器
		a[x][y]=1;

		//开始跑格子
		while(t<=n*n){
			x--;y++;
			if (a[x][y] || (x==0 && y>n)){
				x+=2;y--;
			}
			if (x<=0){
				x=n;
			}
			if (y>n){
				y=1;
			}
			a[x][y]=t++;
		}
		//ofstream "a.txt";
		freopen("a.txt","a+",stdout);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				printf("%5d",a[i][j]);
			}
			delete a[i];
			printf("\n");
		}
		printf("\n");
		delete a;
		freopen("CON","w",stdout);
		printf("\n");
		//system("pause");
		printf("请输入边长为奇数的N(输入0退出游戏)：");
		cin>>n;
	}
	return 0;
}