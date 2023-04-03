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

const int N=300005;
const int inf =1000000000;
int n;
string st;
int tt[N];
int a,b;
void Input() {
  cin>>a>>b;
}
void Solve() {
  int x=b^tt[a-1];
  if(x==0) cout<<a<<'\n';
  else if(x==a) cout<<a+2<<'\n';
  else cout<<a+1<<'\n';
}
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(i,1,300000) tt[i]=tt[i-1]^i;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}