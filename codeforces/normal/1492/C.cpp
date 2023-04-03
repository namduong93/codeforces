#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=2*1e5+5;
int F[N][30],Pre[N];
int n,m;
string s,t;
int main()
{
	//freopen("test.inp","r",stdin);
	cin>>n>>m;
	cin>>s;
	cin>>t;
	s=' '+s;
	t=' '+t;
	fdo(i,n,0)
	{
		fto(j,0,'z'-'a') F[i][j]=F[i+1][j];
		if(i!=n) F[i][s[i+1]-'a']=i+1;
	}
	int st=F[0][t[1]-'a'];
	
	int fn,fn1;
	fn1=m;fn=-1;
	fdo(i,n,1) 
	{
		if(s[i]==t[fn1]) {Pre[fn1]=fn;fn1--;fn=i;}
		if(fn1==1) break;
	}
	if(fn==-1||fn<st) {cout<<0;return 0;}

	int rs=fn-st;
	fto(i,2,m-1)
	{
		st=F[st][t[i]-'a'];
		fn=Pre[i];
		rs=max(rs,fn-st);
		//if(rs==2) cout<<i;
	}
	cout<<rs;
}