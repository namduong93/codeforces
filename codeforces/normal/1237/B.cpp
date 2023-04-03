#include<bits/stdc++.h>
#define fi first
#define se second
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100005;
typedef pair<int,int> pii;
int n,rs;
pii a[N];
int sum[4*N];
int get(int x,int l,int r,int d,int c)
{
    if(d<=l&&r<=c) return sum[x];
    if(c<l||r<d) return 0;
    return get(x*2,l,(l+r)/2,d,c)+get(x*2+1,(l+r)/2+1,r,d,c);
}
void update(int x,int l,int r,int u,int val)
{
    if(u==l&&u==r) {sum[x]=val;return ;}
    if(u<l||r<u) return ;
    update(x*2,l,(l+r)/2,u,val);
    update(x*2+1,(l+r)/2+1,r,u,val);
    sum[x]=sum[x*2]+sum[x*2+1];
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) {int u;cin>>u;a[u].fi=i;}
    fto(i,1,n) {int u;cin>>u;a[u].se=i;}
    sort(a+1,a+1+n);
    //fto(i,1,n) cout<<a[i].fi<<' '<<a[i].se<<'\n';
    fto(i,1,n)
    {
        if(get(1,1,n,a[i].se+1,n)!=0) rs++;
        update(1,1,n,a[i].se,1);
       // if(i==1) cout<<get(1,1,n,5,5);
    }
    cout<<rs;
}