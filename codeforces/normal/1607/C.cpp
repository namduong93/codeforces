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
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;

const int mod=998244353;
const int N=200005;
const int inf =100000000000000000;

int n,a[N];
string st;
int sum[N];

void Input() {
    cin>>n;
    fto(i,1,n) cin>>a[i];
}
void Solve() {
    int rs=-inf;
    sort(a+1,a+1+n);
    fto(i,1,n) {
        sum[i]=sum[i-1]+a[i];
    }
    fto(i,1,n) {
        if(i==1) {
            rs=max(rs,a[i]);
        }
        rs=max(rs,a[i]-a[i-1]);
    }
    cout<<rs<<'\n';
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