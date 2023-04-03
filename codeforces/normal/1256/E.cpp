#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<int,int> pii;
const int oo=1e17;
const int N=200005;
int n,F[N];
pii a[N];
int Trc[N];
pii Min[4*N];
int dem,vt[N];
pii get(int x,int l,int r,int d,int c)
{
    if(c<l||r<d) return {oo,-1};
    if(d<=l&&r<=c) return Min[x];
    return min(get(x*2,l,(l+r)/2,d,c),get(x*2+1,(l+r)/2+1,r,d,c));
}
void update(int x,int l,int r,int u,int val)
{
    if(u==l&&u==r) {Min[x]={val,u};return ;}
    if(u<l||r<u) return ;
    update(x*2,l,(l+r)/2,u,val);
    update(x*2+1,(l+r)/2+1,r,u,val);
    Min[x]=min(Min[x*2],Min[x*2+1]);
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) {cin>>a[i].fi;a[i].se=i;}
    sort(a+1,a+1+n);
    fto(i,1,4*(n+1)) Min[i].fi=oo;
    F[3]=a[3].fi-a[1].fi;
    update(1,0,n,0,0-a[1].fi);
    update(1,0,n,1,oo);
    update(1,0,n,2,oo);
    update(1,0,n,3,F[3]-a[4].fi);
    fto(i,4,n)
    {
        pii tt=get(1,0,n,0,i-3);
        F[i]=tt.fi+a[i].fi;
        Trc[i]=tt.se;
        if(i!=n) update(1,0,n,i,F[i]-a[i+1].fi);
    }
    cout<<F[n]<<' ';
    int uu=n;
    while(uu!=0)
    {
        dem++;
        fto(i,Trc[uu]+1,uu)
        vt[a[i].se]=dem;
        uu=Trc[uu];
    }
    cout<<dem<<'\n';
    fto(i,1,n) cout<<vt[i]<<' ';
}