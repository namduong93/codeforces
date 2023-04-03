#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1e9+7
#define SZ(x) ((int)(x).size())
double minesp=1e-8;
double rs;
double c,m,p,v;
int a[200005];
void tinh(int sl,double C,double M,double P,double tmp)
{
	rs+=P*tmp*(sl+1);
	//cout<<rs<<' ';
	//cout<<M<<' '<<P<<' '<<C;
	if (abs(M)>minesp||C>minesp)
	{
			//cout<<M<<' '<<P<<' '<<C;
		if(M>minesp&&C>minesp)
		{
			tinh(sl+1,C+min(v,M)/2,M-min(v,M),P+min(v,M)/2,tmp*M);
		}
			//cout<<M<<' '<<P<<' '<<C;
		if(M>minesp&&C>minesp)
		{
			tinh(sl+1,C-min(v,C),M+min(v,C)/2,P+min(v,C)/2,tmp*C);
			return ;
		}
			//cout<<M<<' '<<P<<' '<<C;
		if(C<minesp)
		{
			tinh(sl+1,0,M-min(v, M),P+min(v, M),tmp*M);
			return ;
		}
		if(M<minesp)
		{
				tinh(sl+1,C-min(v,C),0,P+min(v,C),tmp*C);
		}
			//cout<<M<<' '<<P<<' '<<C;
	}
}
#undef int
int Test;
int main()
{
	#define int long long
	//freopen("test.inp","r",stdin);
	cin>>Test;
	fto(i,1,Test)
	{
		cin>>c>>m>>p>>v;
		rs=0;
		tinh(0,c,m,p,1);
		//cout<<rs<<' ';
		cout<<fixed<<setprecision(8)<<rs<<'\n';
	}
}