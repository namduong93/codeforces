#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=300005;
int dau,cuoi,mid,res;
int a[N],b[N];
int n,m;
bool check(int op)
{
    if(n==1) return true;
    fto(i,1,n)
    {
        if(a[i]+op<m)
        {
            if(a[i]+op<b[i-1]) return false;
            b[i]=max(a[i],b[i-1]);
        }
        else
        {
            //if(i==2) cout<<(a[i]+op)%m;
            if((a[i]+op)%m>=b[i-1]) b[i]=b[i-1];
            else
            b[i]=max(a[i],b[i-1]);
        }
    }
    return true;
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>m;
    fto(i,1,n) cin>>a[i];
    dau=0;cuoi=m-1;
    res=-1;
    while(dau<=cuoi)
    {
        mid=(dau+cuoi)/2;
        if(check(mid)) {cuoi=mid-1;res=mid;}
        else dau=mid+1;
    }
    cout<<res;
}