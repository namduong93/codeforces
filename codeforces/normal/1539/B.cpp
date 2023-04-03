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

int n,q;
int sum[100005];
string str;
int main()
{
  //freopen("test.inp","r",stdin);
  cin>>n>>q;
  cin>>str;
  str=' '+str;
  fto(i,1,n)
  sum[i]=sum[i-1]+(str[i]-'a'+1);
  fto(i,1,q)
  {
    int u,v;
    cin>>u>>v;
    cout<<sum[v]-sum[u-1]<<'\n';
  }
}