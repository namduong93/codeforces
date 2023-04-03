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

const int N=100005;

int Test;

int n,x;
int a[N];
void Input()
{
  cin>>n>>x;
  fto(i,1,n) cin>>a[i];
}
void Solve()
{
  int rs1,rs2;
  rs1=rs2=0;
  fto(i,1,n)
  {
    rs2+=a[i];
    rs1+=(a[i]+x-1)/x;
  }
  rs2+=x-1;
  cout<<rs2/x<<' '<<rs1<<'\n';
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