#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define int long long
using namespace std;
int test,n,m;
int kq;
main()
{
    //freopen("test.inp","r",stdin);
    cin>>test;
    fto(tt,1,test)
    {
        cin>>n>>m;
        int rr=n/m;
        kq=0;
        fto(i,1,rr%10)
        {
            kq+=(m%10*i)%10*(rr/10+1);
        }
        fto(i,rr%10+1,9)
        {
            kq+=(m%10*i)%10*(rr/10);
        }
        cout<<kq<<'\n';
    }
}