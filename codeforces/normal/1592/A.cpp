/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
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
const int inf =1000000000;
int n,H,a[N];
string st;
int sum=0; 
int dem=0;
void Input() {
  cin>>n>>H;
  fto(i,1,n) cin>>a[i];
  sort(a+1,a+1+n);

}
void Solve() {
  int cc=a[n]+a[n-1];
  int rs=(H/cc)*2;
  H=H%cc;
  if(H==0) {cout<<rs<<'\n';return;}
  if(H>a[n]) {cout<<rs+2<<'\n';return;}
  {cout<<rs+1<<'\n';return;}
}
int32_t main() {
  if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }

  return 0;
}