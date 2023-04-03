#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<int,int> pii;
const int N=2e5+7;
set<pii> S;
int n,m;
pii a[N];
int bb[N];
int pos[N],k[N];
int Ans[N],sum[4*N];
void read(int &v)
{
    char c;do{c=getchar();} while(!isdigit(c));
    v=c-'0'; while(isdigit(c=getchar())) v=v*10+c-'0';
}
bool cmp(pii c1,pii c2)
{
    if(c1.fi==c2.fi) return c1.se>c2.se;
    else return c1.fi<c2.fi;
}
struct ndv
{
    int fii,see,pos;
    bool operator < (const ndv &tmp)
    {
        if(fii==tmp.fii) return see<tmp.see;
        return fii<tmp.fii;
    }
};
ndv gg[N];
int get(int x,int l,int r,int d,int c)
{
    if(r<d||c<l) return 0;
    if(d<=l&&r<=c) return sum[x];
    return get(x*2,l,(l+r)/2,d,c)+get(x*2+1,(l+r)/2+1,r,d,c);
}
void update(int x,int l,int r,int u,int val)
{
    if(u==l&&u==r) {sum[x]+=val;return ;}
    if(u<l||r<u) return ;
    update(x*2,l,(l+r)/2,u,val);
    update(x*2+1,(l+r)/2+1,r,u,val);
    sum[x]=sum[x*2]+sum[x*2+1];
}
void chatnp(int xx,int id)
{
    int dau=1;int cuoi=n;
    int rs=-1;
    while(dau<=cuoi)
    {
        int mid=(dau+cuoi)/2;
        if(get(1,1,n,1,mid)>=xx)
        {
            cuoi=mid-1;
            rs=mid;
        }
        else dau=mid+1;
    }
    Ans[id]=bb[rs];
}
int main()
{
    //freopen("test.inp","r",stdin);
    read(n);
    fto(i,1,n) {read(a[i].fi);a[i].se=i;bb[i]=a[i].fi;}
    sort(a+1,a+1+n,cmp);
    read(m);
    int l=n;
    fto(i,1,m)
    {
        read(gg[i].fii);read(gg[i].see);
        gg[i].pos=i;
    }
    sort(gg+1,gg+1+m);
    fto(i,1,m)
    {
        k[i]=gg[i].fii;pos[i]=gg[i].see;
        int dist=k[i]-k[i-1];
        fto(i,1,dist)
        {
            update(1,1,n,a[l].se,1);
            l--;
        }
        chatnp(gg[i].see,gg[i].pos);
    }
    fto(i,1,m) cout<<Ans[i]<<'\n';
}