#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=2*1e5+5;
int n,k,rs,kq=1e17;
int a[N],sum[N],D[N];
int f[20];
priority_queue<int,vector<int>,greater<int> > heap;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin>>n>>k;
    fto(i,1,n) {cin>>a[i];D[a[i]]++;}
    fto(i,1,2*1e5+3)
    sum[i]=sum[i-1]+D[i];
    fto(tt,1,n)
    {
        int Pow=1;
        fto(i,0,17)
        {
            if(i!=0)
            Pow=Pow*2;
            int st=a[tt]/Pow;
            int Pow1=1;
            if(st==0) continue;
            memset(f,0,sizeof f);
            fto(gg,0,17)
            {
                if(gg!=0)
                Pow1=Pow1*2;
                f[gg]=sum[min(200001ll,( (st+1)*Pow1-1 ) )]-sum[min(200001ll,(st*Pow1)-1)];
            }
            int dem=0;
            dem+=f[0];
            rs=0;
            if(dem>=k) {kq=min(kq,rs);continue;}
            fto(gg,0,16)
            {
                dem+=f[gg+1];
                rs+=f[gg+1]*(gg+1);
                if(dem>=k) {kq=min(kq,rs-(dem-k)*(gg+1));break;}
            }
        }
    }
    fto(i,1,n)
    {
        int dem=0;
        while(a[i]!=0) {a[i]=a[i]/2;dem++;}
        heap.push(dem);
    }
    rs=0;
    fto(i,1,k)
    {
        rs+=heap.top();
        heap.pop();
    }
    kq=min(kq,rs);
    cout<<kq;
}