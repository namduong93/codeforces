#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100001;
int dsu[5*N];
int n,m,gg,kk;
int root(int u)
{
    while(dsu[u]>0)
    u=dsu[u];
    return u;
}
bool Union(int u,int v)
{
    u=root(u);
    v=root(v);
    if(u==v) return false;
    if(dsu[u]>dsu[v]) swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
    return true;
}
int main()
{
    cin>>n>>m;
    fto(i,1,n) dsu[i]=-1;
    fto(i,1,m)
    {
        int u;
        cin>>u;
        if(u>=1)
        cin>>gg;
        fto(i,2,u)
        {
            cin>>kk;
            Union(gg,kk);
        }
    }
    fto(i,1,n)
    {
        int u=root(i);
        cout<<-dsu[u]<<' ';
    }
}