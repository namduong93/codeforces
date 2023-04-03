#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
using namespace std;
const int N=100005;
const int oo=1000000005;
int n;
pair<int,int> a[N];
int r1,l1,l2;
int d[N][3];
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) cin>>a[i].fi>>a[i].se;
    sort(a+1,a+1+n);
    a[0]={-oo,0};
    fto(i,1,n)
    {
        r1=a[i-1].fi+a[i-1].se;
        l1=a[i-1].fi-a[i-1].se;
        d[i][0]=max(d[i-1][1],d[i-1][0]);
        if(r1<a[i].fi) d[i][0]=max(d[i][0],d[i-1][2]);
        l2=a[i].fi-a[i].se;
        if(r1<l2) d[i][1]=max(d[i-1][2]+1,max(d[i-1][1]+1,d[i-1][0]+1));
        else
        {
            if(a[i-1].fi<l2) d[i][1]=max(d[i-1][0]+1,d[i-1][1]+1);
        }
        if(r1<a[i].fi) d[i][2]=max(d[i-1][2]+1,max(d[i-1][0]+1,d[i-1][1]+1));
        else d[i][2]=max(d[i-1][0]+1,d[i-1][1]+1);
    }
    cout<<max(d[n][0],max(d[n][1],d[n][2]));
   // cout<<d[3][2];
}