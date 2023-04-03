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
int m;
int a[3][N];
int s[3][N];
void Input() {
  cin>>m;
  fto(i,1,2)
  fto(j,1,m) cin>>a[i][j];
}
void Solve() {
  int rs=2000000000;
  fto(i,1,2)
  fto(j,1,m) {
    s[i][j]=s[i][j-1]+a[i][j];
  }
  fto(i,1,m) {
    rs=min(rs,max(s[1][m]-s[1][i],s[2][i-1]));
  }
  cout<<rs<<'\n';
}
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