#include<limits>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL __int64
#define eps 1e-8
#define pi acos(-1)
#define delta 0.98 //模拟退火递增变量
#define INF 0x7fffffff
using namespace std;
class Solution {
public:
	string ss;
	int m;
	int l;
	map<char,int>mp;
	vector<string>ans;
	void ha(string s){
		int n=s.length();
		int a[3]={0,0,0};
		int b[2]={0,0};
		int t=0;
		int t1=0;
		int i=0;
		while(i<n){
			int k=0;
			while(i<n && s[i]>='0' && s[i]<='9'){
				k=k*10+s[i]-'0';
				i++;
			}
			a[t++]=k; //取数字 
			if (t==3){
				if (b[1]==3 && b[0]!=3){
					a[1]=a[1]*a[2];
					t=2;
					t1=1;
				}else{
					if (b[0]==1) a[0]+=a[1];
					else if (b[0]==2) a[0]-=a[1];
					else a[0]*=a[1];
					a[1]=a[2];
					b[0]=b[1];
					t=2;
					t1=1;	
				}
			}
			if (i==n) break;
			b[t1++]=mp[s[i++]]; //取符号
		}
		if (t1==1){
			if (b[0]==1) a[0]+=a[1];
			else if (b[0]==2) a[0]-=a[1];
			else a[0]*=a[1];
		}
		if (a[0]==m){
			ans.push_back(s);
		//	cout<<s<<" "<<a[0]<<endl;
		}
	}
	void go(string s,int k){
		s+=ss[k];
		if (k==l-1) ha(s);
		else
			for (int i=0;i<4;i++){
				int f=s.length()-1;
				while(s[f]=='0') f--;
				if (i==0 && (s[s.length()-1]!='0' || (s[f]>='1' && s[f]<='9'))) go(s,k+1);
				//if (i==0) go(s,k+1);
				else if (i==1) go(s+"+",k+1);
				else if (i==2) go(s+"-",k+1);
				else if (i==3) go(s+"*",k+1);
			}
		return;
	}
    vector<string> addOperators(string n, int t) {
    	if (n=="" || n=="2147483648") return ans;
    	if (n=="2147483647"){
    		ans.push_back(n);
    		return ans;
    	}
    	mp['+']=1;
    	mp['-']=2;
    	mp['*']=3;
		ss=n;
		m=t;
		l=n.length();
		go("",0);
		return ans;
    }
}zz;
int main(){
	string s;
	int n;
	cout<<"请输入一连串数字(按回车键结束)"<<endl;
	cin>>s;
	cout<<"请输入一个数字(按回车键结束)"<<endl;
	cin>>n;
	vector<string>k;
	k=zz.addOperators(s,n);
	for (int i=0;i<k.size();i++){
		cout<<k[i]<<endl;
	}
	system("pause");
	return 0;
}