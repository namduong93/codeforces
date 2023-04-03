#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=400005;
int Test;
int Tham[N];
int rs[N];
vector<int> a[N],arv[N];
int n,m;
bool cycle[N];
int Num[N];
void rset()
{
  fto(i,1,n) Tham[i]=0;
  fto(i,1,n) rs[i]=3;
  fto(i,1,n)
  if(a[i].size())
  a[i].clear();

  fto(i,1,n)
  if(arv[i].size())
  arv[i].clear();
  fto(i,1,n) Num[i]=0;

  fto(i,1,n) cycle[i]=false;
}
void dfsSt(int u)
{
  Tham[u]=1;
  if(a[u].size())
  fto(i,0,a[u].size()-1)
  {
    int v=a[u][i];
    if(!Tham[v]) dfsSt(v);
    else if(Tham[v]==1) cycle[u]=true;
  }
  Tham[u]=2;
}
void dfsF(int u)
{
  Tham[u]=1;
  if(a[u].size())
  fto(i,0,a[u].size()-1)
  {
    int v=a[u][i];
    if(!Tham[v]) dfsF(v);
  }
}
void dfsRv(int u)
{
  if(u==1) return ;
  Tham[u]=1;
  if(arv[u].size())
  fto(i,0,arv[u].size()-1)
  {
    int v=arv[u][i];
    if(!Tham[v]) dfsRv(v);
    Num[u]+=Num[v];
    //if(u==4) cout<<v<<' ';
  }
}
int main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>n>>m;
    rset();
    fto(i,1,m)
    {
      int u,v;
      cin>>u>>v;
      a[u].push_back(v);
      arv[v].push_back(u);
    }
    dfsSt(1);

    fto(i,1,n)
    {
      if(!Tham[i]) rs[i]=0;
      else Tham[i]=0;
    }
    fto(i,1,n)
    if(cycle[i])
    {
      dfsF(i);
    }

    fto(i,1,n)
    if(Tham[i])
    rs[i]=-1;

    Num[1]=1;
    fto(i,1,n) Tham[i]=false;

    fto(i,2,n)
    if(rs[i]!=0&&rs[i]!=-1)
    if(!Tham[i])
    dfsRv(i);

    fto(i,1,n)
    if(rs[i]!=0&&rs[i]!=-1)
    if(Num[i]==1) rs[i]=1;
    else rs[i]=2;

    fto(i,1,n) cout<<rs[i]<<' ';
    cout<<'\n';
  }
}