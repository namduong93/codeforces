#include<bits/stdc++.h>
#define fii first
#define see second
#define int long long
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<int,int> pii;
const int N=3e5+9;
const int oo=1e18;
int n,m;
vector<pii> a[N];

int dsu[N];
bool r1[N],r2[N];

vector<pii> b[N];
int Rank[N],dis[N];
int Par[N][19];

vector<int> s1,s2;
priority_queue< pii, vector<pii>, greater<pii> >heap;
int d[42][N];

int q,rs;
struct ndv
{
    int fi,se,weight;
};
ndv edge[N];
//-----------------------------------------------
int root(int u)
{
    while(dsu[u]>0)
    u=dsu[u];
    return u;
}
int Union(int u,int v)
{
    u=root(u);
    v=root(v);
    if(u==v) return 0;
    if(dsu[u]>dsu[v]) swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
    return 1;
}
//-----------------------------------------------
void DFS(int u)
{
    if(b[u].size())
    fto(i,0,b[u].size()-1)
    {
        pii v=b[u][i];
        if(v.fii!=Par[u][0])
        {
            Rank[v.fii]=Rank[u]+1;
            Par[v.fii][0]=u;
            dis[v.fii]=dis[u]+v.see;
            DFS(v.fii);
        }
    }
}
int LCA(int u,int v)
{
    if(Rank[u]<Rank[v]) swap(u,v);
    fdo(i,17,0)
    if(Rank[Par[u][i]]>=Rank[v])
    u=Par[u][i];
    if(u==v) return u;
    fdo(i,17,0)
    if(Par[u][i]!=Par[v][i])
    {
        u=Par[u][i];
        v=Par[v][i];
    }
    return Par[u][0];
}
//-----------------------------------------------
void dijsk(int start,int D[])
{
    fto(i,1,n)
    D[i]=oo;
    D[start]=0;
    heap.push({0,start});
    while(!heap.empty())
    {
        pii x=heap.top();
        heap.pop();
        if(D[x.see]!=x.fii) continue ;
        fto(i,0,a[x.see].size()-1)
        {
            pii v=a[x.see][i];
            if(D[v.fii]>D[x.see]+v.see)
            {
                D[v.fii]=D[x.see]+v.see;
                heap.push({D[v.fii],v.fii});
            }
        }
    }
}
//-----------------------------------------------
void make_edge()
{
    fto(i,1,m)
    {
        r1[i]=Union(edge[i].fi,edge[i].se);
        if(r1[i])
        {
            b[edge[i].fi].push_back({edge[i].se,edge[i].weight});
            b[edge[i].se].push_back({edge[i].fi,edge[i].weight});
        }
        else
        {
            s1.push_back(i);
            if(!r2[edge[i].fi]) {s2.push_back(edge[i].fi);r2[edge[i].fi]=true;}
            if(!r2[edge[i].se]) {s2.push_back(edge[i].se);r2[edge[i].se]=true;}
        }
    }
    //canh
    DFS(1);
    fto(i,1,17)
    fto(u,1,n)
    Par[u][i]=Par[Par[u][i-1]][i-1];
    Rank[0]=-1;

    //dinh
    sort(s2.begin(),s2.end());
    if(s2.size())
    fto(i,0,s2.size()-1)
    dijsk(s2[i],d[i]);
}
//-----------------------------------------------
void solve()
{
    cin>>q;
    fto(tt,1,q)
    {
        int u,v,root;
        cin>>u>>v;
        rs=oo;
        root=LCA(u,v);
        rs=dis[u]-dis[root]+dis[v]-dis[root];
        if(s1.size())
        fto(i,0,s1.size()-1)
        {
            int uu,vv,vtuu,vtvv;
            uu=edge[s1[i]].fi;
            vv=edge[s1[i]].se;
            //if(tt==1) cout<<uu<<' '<<vv<<'\n';
            vtuu=lower_bound(s2.begin(),s2.end(),uu)-s2.begin();
            vtvv=lower_bound(s2.begin(),s2.end(),vv)-s2.begin();
            rs=min(rs,edge[s1[i]].weight+d[vtuu][u]+d[vtvv][v]);
            rs=min(rs,edge[s1[i]].weight+d[vtvv][u]+d[vtuu][v]);
        }
        cout<<rs<<'\n';
    }
}
//-----------------------------------------------
main()
{
    //29-10-11-26-31
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    //freopen("Traihe47.inp","r",stdin);
    //freopen("Traihe47.out","w",stdout);
    cin>>n>>m;
    fto(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
        edge[i]={u,v,w};
    }
    make_edge();
    solve();
}