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

const int N=505;
int Test;
struct CMD
{
  char ch;
  int x;
} cmd[N];
int n;
ll f[N][N];
ll rs;
void Input()
{
  cin>>n;
  fto(i,1,n)
  {
    cin>>cmd[i].ch;
    if(cmd[i].ch=='-') continue;
    cin>>cmd[i].x;
  }
}
void Solve()
{
  fto(tt,1,n)
  if(cmd[tt].ch=='+')
  {
    fto(i,0,n) fto(j,0,n) f[i][j]=0;
    f[0][0]=1;
    fto(i,1,n)
    fto(j,0,i-1)
    {
      if(i!=tt) f[i][j]=(f[i][j]+f[i-1][j])%mod;
      if(i<tt)
      {
        if(cmd[i].ch=='-')
        f[i][max(j-1,0ll)]=(f[i][max(j-1,0ll)]+f[i-1][j])%mod;
        if(cmd[i].ch=='+')
          if(cmd[i].x>cmd[tt].x)
          f[i][j]=(f[i][j]+f[i-1][j]);
          else
            f[i][j+1]=(f[i][j+1]+f[i-1][j])%mod;
      }
      if(i>tt)
      {
        if(cmd[i].ch=='-'&&j!=0)
        f[i][j-1]=(f[i][j-1]+f[i-1][j])%mod;
        if(cmd[i].ch=='+')
          if(cmd[i].x>cmd[tt].x)
          f[i][j]=(f[i][j]+f[i-1][j])%mod;
          else
            if(cmd[i].x<cmd[tt].x)
            f[i][j+1]=(f[i][j+1]+f[i-1][j])%mod;
            else f[i][j]=(f[i][j]+f[i-1][j])%mod;
      }
      if(i==tt)
      {
        f[i][j]=(f[i][j]+f[i-1][j])%mod;
      }
    }
    ll sum=0ll;
    fto(i,0,n) sum=(sum+f[n][i])%mod;
    rs=(rs+(cmd[tt].x*sum)%mod)%mod;
  //  if(tt==2) cout<<f[3][0];
  }
  cout<<rs;
}
int32_t main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  Test=1;
  fto(iTest,1,Test)
  {
    Input();
    Solve();
  }
}