#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
int n,p,k;
int a[N],sum[N];
main()
{
    //freopen("test.inp","r",stdin);
    int Test;
    cin>>Test;
    fto(iTest,1,Test)
    {
        cin>>n>>p>>k;
        fto(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        fto(i,1,n)
        {
            sum[i]=sum[i-1]+a[i];
            if(sum[i]>p) sum[i]=p+1;
        }
        int kq=0;
        fto(i,0,k-1)
        if(sum[i]<=p&&i<=n)
        {
            kq=max(kq,i);
            int tt=sum[i];
            int cc=i+k;
            while(cc<=n)
            {
                if(tt+a[cc]>p) break;
                tt+=a[cc];
                kq=max(kq,cc);
                cc+=k;
            }
        }
        cout<<kq<<'\n';
    }
}