#include <bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200002;
int n,k,t;
int a[N];
int dau,cuoi;
int out(int cc)
{
    fto(i,1,n-k)
    if(a[i+k]<=2*cc+a[i])
    return (a[i+k]+a[i])/2;
}
bool chatnp(int x)
{
    fto(i,1,n-k)
    if(a[i+k]<=2*x+a[i])
    return true;
    return false;
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>t;
    while (cin>>n>>k)
    {
        fto(i,1,n) cin>>a[i];
        sort(a+1,a+n+1);
        int res=-1;
        dau=0;cuoi=500000000;
        while (dau<=cuoi)
        {
            int mid=(dau+cuoi)/2;
            if (chatnp(mid))
            {
                res=mid;
                cuoi=mid-1;
            }
            else dau=mid+1;
        }
        if(res!=-1)
        cout<<out(res)<<'\n';
    }
}