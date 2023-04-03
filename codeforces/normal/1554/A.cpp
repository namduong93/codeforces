/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
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

int n,a[N];
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
  a[0]=a[n+1]=0;
}
void Solve() {
  int rs=0;
  fto(i,1,n) {
     rs=max(rs,a[i]*a[i-1]);
     rs=max(rs,a[i]*a[i+1]);
   }
   cout<<rs<<'\n';
}
#undef int
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}