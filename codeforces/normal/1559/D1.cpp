/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
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
#define pii pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=100005;
const int inf =1000000000;
int n,a[N];
string st;
int m1,m2;
vector<int> a1[N],a2[N];
int Tham1[N],Tham2[N];
int lt1,lt2;
vector<pii> rs;
void Input() {
  cin>>n>>m1>>m2;
  fto(i,1,m1) {
    int u,v;
    cin>>u>>v;
    a1[u].push_back(v);
    a1[v].push_back(u);
  }
  fto(i,1,m2) {
    int u,v;
    cin>>u>>v;
    a2[u].push_back(v);
    a2[v].push_back(u);
  }
}
void dfs1(int u) {
  Tham1[u]=lt1;
  if(a1[u].size())
  fto(i,0,a1[u].size()-1) {
    int v=a1[u][i];
    if(!Tham1[v]) dfs1(v);
  }
}
void dfs2(int u) {
  Tham2[u]=lt2;
  if(a2[u].size())
  fto(i,0,a2[u].size()-1) {
    int v=a2[u][i];
    if(!Tham2[v]) dfs2(v);
  }
}
void Solve() {

  fto(i,1,n) {
    if(!Tham1[i]) {
      lt1++;
      dfs1(i);
    }
  }

  fto(i,1,n) {
    if(!Tham2[i]) {
      lt2++;
      dfs2(i);
    }
  }

  //cout<<lt2;
  fto(u,1,n)
  fto(v,u+1,n) {
    if(Tham1[u]!=Tham1[v]&&Tham2[u]!=Tham2[v]) {
      rs.push_back({u,v});
      int tt1=Tham1[u];
      int tt2=Tham2[u];
      fto(i,1,n) {
        if(Tham1[i]==tt1)
        Tham1[i]=Tham1[v];
        if(Tham2[i]==tt2)
        Tham2[i]=Tham2[v];
      }
    }
  }
  cout<<rs.size()<<'\n';
  if(rs.size())
  fto(i,0,rs.size()-1) cout<<rs[i].first<<' '<<rs[i].second<<'\n';
}
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  Test=1;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}