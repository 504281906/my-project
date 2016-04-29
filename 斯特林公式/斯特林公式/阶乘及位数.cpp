#include <iostream>
#include <cmath>
#include <cstdio>
#define Pi acos(-1)
#define E exp(1)
using namespace std;
double pows(double a,int b){
	double s=1;
	double k=a;
	while (b){
		if (b&1)
			s*=k;
		k*=k;
		b>>=1;
	}
	return s;
}
int a[10000];
int main(){
	//cout<<Pi<<" "<<E<<endl;
	long long n;
	cin>>n;
	long long s=sqrt(2*Pi*n)*pows(n/E,n);
	int k=ceil(log10(2*Pi*n)/2+log10(n/E)*n);
	cout<<s<<" "<<k<<endl;
	int m=0;
	a[0]=1;
	for (int i=1;i<=n;i++){
		int c=0;
		for (int j=0;j<=m;j++){
			a[j]=a[j]*i+c;
			c=a[j]/10000;
			a[j]%=10000;
		}
		if (c>0){
			m++;
			a[m]=c;
		}
	}
	cout<<a[m];
	for (int i=m-1;i>=0;i--)
		printf("%4.4ld",a[i]);
	cout<<endl;
	system("pause");
}