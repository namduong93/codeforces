/**
 *    author:  namduong93
 *    created: unknown
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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

const int N=300005;

int Test;
int n,m;
int k[N],c[N];
int sum2[N],sum1[N];
void Input()
{
  cin>>n>>m;
  fto(i,1,n) cin>>k[i];
  fto(i,1,m) cin>>c[i];
}
void Solve()
{
  ll rs=1e18;
  sort(k+1,k+1+n);
  fto(i,1,m)
  sum2[i]=sum2[i-1]+c[i];

  fto(i,1,n)
  sum1[i]=sum1[i-1]+c[k[i]];

  fto(x,0,min(n,m))
  {
    rs=min(rs,sum2[x]+sum1[n-x]);
  }
  cout<<rs<<'\n';
}
#undef int
int main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin>>Test;
  fto(iTest,1,Test)
  {
    Input();
    Solve();
  }
}