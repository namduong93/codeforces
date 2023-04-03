#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=3e5+5;
const int oo=1e15;
typedef pair<int,int> pii;
int n,m,st,dem;
int D[N];
pii Boo[N];
vector<pii> a[N];
priority_queue< pii, vector<pii>, greater<pii> >heap;
struct ndv
{
    int fii,see,weight;
};
ndv edge[N];
void dijsk(int start)
{
    D[start]=0;
    heap.push({0,start});
    while(!heap.empty())
    {
        pii x=heap.top();
        heap.pop();
        if(D[x.se]!=x.fi) continue ;
        if(a[x.se].size())
        fto(i,0,a[x.se].size()-1)
        {
            pii v=a[x.se][i];
            if(D[v.se]>x.fi+v.fi)
            {
                D[v.se]=x.fi+v.fi;
                heap.push({D[v.se],v.se});
            }
        }
    }
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>m;
    fto(i,1,n) D[i]=oo;
    fto(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
        edge[i]={u,v,w};
    }
    cin>>st;
    dijsk(st);
    fto(i,1,m)
    {
        int u,v,w;
        u=edge[i].fii;
        v=edge[i].see;
        w=edge[i].weight;
        if(D[v]==D[u]+w)
        {
            if(Boo[v].fi==0||Boo[v].se>w)
            {
                Boo[v]={u,w};
            }
        }
        if(D[u]==D[v]+w)
        {
            if(Boo[u].fi==0||Boo[u].se>w)
            {
                Boo[u]={v,w};
            }
        }
    }
    fto(i,1,m)
    {
        int u,v,w;
        u=edge[i].fii;
        v=edge[i].see;
        w=edge[i].weight;
        if(Boo[v].fi==u) {dem+=w;continue;}
        if(Boo[u].fi==v) {dem+=w;continue;}
    }
    cout<<dem<<'\n';
    fto(i,1,m)
    {
        int u,v,w;
        u=edge[i].fii;
        v=edge[i].see;
        w=edge[i].weight;
        if(Boo[v].fi==u) {cout<<i<<' ';continue;}
        if(Boo[u].fi==v) {cout<<i<<' ';continue;}
    }
}