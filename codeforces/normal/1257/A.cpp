#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T,n,x,a,b;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {cin>>n>>x>>a>>b;
    if(a>b) swap(a,b);
    if(x>a-1+n-b) cout<<n-1<<'\n';
    else
    {
        int t1=n-b;
        int t2=a-1;
        a-=min(x,t1);
        x-=min(x,t1);
        b+=min(x,t2);
        x-=min(x,t2);
        cout<<b-a<<'\n';
    }}
}