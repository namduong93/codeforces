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
#define inf 10000000000000000
#define SZ(x) ((int)(x).size())

const int N=100005;

int n;
double a[N];
double sum[N];
double sum2[N];
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
  fto(i,1,n) sum[i]=sum[i-1]+a[i];
  sum2[n+1]=0;
  fdo(i,n,1) sum2[i]=sum2[i+1]+a[i];
}
void Solve() {
  double rs=-inf;
  fto(i,1,n) rs=max(rs,a[i]);
  rs+=(sum[n]-rs)/(double)(n-1);
  cout<<fixed<<setprecision(9)<<rs<<'\n';
}
int main() {
 // freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}