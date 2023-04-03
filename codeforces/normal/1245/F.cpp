#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T,l,r;
bool vs[35][2][2];
int nho[35][2][2];
int getbit(int x,int i)
{
    return (x>>i)&1ll;
}
int get(int i,int isless1,int isless2,int val1,int val2)
{
    //cout<<i<<' '<<isless1<<' '<<isless2<<'\n';
    if(vs[i][isless1][isless2]) return nho[i][isless1][isless2];
    vs[i][isless1][isless2]=true;
    if(i==0)
    {
        nho[i][isless1][isless2]=1;
        return 1;
    }
    nho[i][isless1][isless2]=0;
    int f1,f2;
    if(isless1==1) f1=1; else f1=getbit(val1,i-1);

    if(isless2==1) f2=1; else f2=getbit(val2,i-1);

    fto(g1,0,f1)
    fto(g2,0,f2)
    {
        if(g1==1&&g2==1) continue;
        int new1=isless1|(g1<f1);
        int new2=isless2|(g2<f2);
        nho[i][isless1][isless2]+=get(i-1,new1,new2,val1,val2);
       // if(i==1&&isless1==1&&isless2==1) cout<<new1<<' '<<new2<<get(2,1,0,4,4)<<'\n';
    }
    return nho[i][isless1][isless2];
}
int Get(int x1 , int x2)
{
	memset(vs , 0 , sizeof vs);
	return get(32 , 0 , 0, x1 ,x2);
}
void Solve()
{
	if(l != 0) cout << Get(r , r) - Get(l - 1 , r) - Get(r , l - 1) + Get(l - 1 , l - 1) << '\n';
	else
	{
		cout << Get(r , r) << '\n';
	}
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        cin>>l>>r;
        Solve();
    }
}