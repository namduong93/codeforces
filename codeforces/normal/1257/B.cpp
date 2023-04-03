#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n)
    {
        int u,v;
        cin>>u>>v;
        int Max=u;
        if(u==1&&v!=1) {cout<<"NO"<<'\n';continue;}
        bool kt=true;
        while(1)
        {
            if(u>=v) break;
            if(u%2==1) u=(u-1)*3/2;
            else u=u*3/2;
            if(u<=Max) {kt=false;break;}
            Max=max(Max,u);
        }
        if(!kt) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}