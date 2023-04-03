#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,m,rs;
struct ndv
{
    int x,y;
};
ndv edge[25];
int x[8];
bool Boo[7][7];
void update()
{
    memset(Boo,false,sizeof Boo);
    int dem=0;
    fto(i,1,m)
    {
        int u=x[edge[i].x];
        int v=x[edge[i].y];
        if(u>v) swap(u,v);
        if(!Boo[u][v]) {dem++;Boo[u][v]=true;}
    }
    rs=max(rs,dem);
}
void Try(int i)
{
    fto(j,1,6)
    {
        x[i]=j;
        if(i==n) update();
        else Try(i+1);
    }
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>m;
    fto(i,1,m)
    cin>>edge[i].x>>edge[i].y;
    Try(1);
    cout<<rs;
}