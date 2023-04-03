#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())
#define int long long

const int N=1000;

int tong(int ss)
{
  if(ss%2==0) return (ss/2*(ss+1));
  else
  return (ss*((ss+1)/2));
}
int k;
#undef int
int main()
{
  #define int long long
  //freopen("test.inp","r",stdin);
  cin>>k;
  fto(i,1,k)
  {
    int n,x,t;
    cin>>n>>x>>t;
    if(t/x==0) cout<<0<<'\n';
    else
    {
      cout<<max(0ll,n-t/x)*(t/x)+tong(min(t/x-1,n-1))<<'\n';
    }
  }
}