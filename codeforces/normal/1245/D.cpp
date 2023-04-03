#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=5000000;
typedef pair<int,int> pii;
int n,dem,rs;
int c[2002],k[2002];
pii a[N];
int dsu[2002];
vector<pii> gg;
bool Boo[2002];
int root(int u)
{
    while(dsu[u]>0) u=dsu[u];
    return u;
}
struct ndv
{
    int f,s,w;
    bool operator < (const ndv &tmp) const
    {
        return w<tmp.w;
    }
};
ndv edge[N];
int Union(int u,int v)
{
    u=root(u);v=root(v);
    if(u==v) return 0;
    if(dsu[u]>dsu[v]) swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
    return 1;
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) cin>>a[i].fi>>a[i].se;
    fto(i,1,n) cin>>c[i];
    fto(i,1,n) cin>>k[i];
    fto(i,1,n) dsu[i]=-1;
    fto(i,1,n)
    fto(j,i+1,n)
    {
        dem++;
        edge[dem]={i,j,(k[i]+k[j])*(abs(a[i].fi-a[j].fi)+abs(a[i].se-a[j].se))};
    }
    fto(i,1,n)
    {
        dem++;
        edge[dem]={i,n+1,c[i]};
    }
    sort(edge+1,edge+1+dem);
    fto(i,1,dem)
    {
        int tt=Union(edge[i].f,edge[i].s)*edge[i].w;
        if(tt)
        {
            rs+=tt;
            if(edge[i].s==n+1) Boo[edge[i].f]=true;
            else
            {
                gg.push_back({edge[i].f,edge[i].s});
            }
        }
    }
    cout<<rs<<'\n';
    cout<<n-gg.size()<<'\n';
    fto(i,1,n) if(Boo[i]) cout<<i<<' ';
    cout<<'\n'<<gg.size()<<'\n';
    if(gg.size()!=0)
    fto(i,0,gg.size()-1) cout<<gg[i].fi<<' '<<gg[i].se<<'\n';
}