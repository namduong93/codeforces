#include<bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int Test;
	cin>>Test;
	while(Test--)
	{
		int p,a,b,c;
		cin>>p>>a>>b>>c;
		if(p%a==0) a=p/a*a; else a=(p/a+1)*a;
		if(p%b==0) b=p/b*b; else b=(p/b+1)*b;
		if(p%c==0) c=p/c*c; else c=(p/c+1)*c;
		cout<<min(a,min(b,c))-p<<'\n';
	}
}