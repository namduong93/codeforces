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
#define pii pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=100005;

int Test;

int n,x;
pii a[N];
void Input()
{
  cin>>n>>x;
  fto(i,1,n) {cin>>a[i].fi;a[i].se=1;}
}
void Solve()
{
  ll rs=0ll;
  fto(i,1,n) rs+=a[i].fi;
  while(1)
  {
    bool Stop=false;
    fto(i,1,n)
    {
      if(a[i].fi%x==0)
      {
        a[i].se*=x;
        a[i].fi/=x;
        rs+=a[i].fi*a[i].se;
      }
      else {Stop=true;break;}
    }
    if(Stop) break;
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