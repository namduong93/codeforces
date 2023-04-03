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
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;
typedef long long ll;

const int mod=998244353;
const int N=200005;
const int inf =1e9+7;

int n,a[N],k;
string st;
int dp[N];
void Solve() {
    cin>>n>>k;
    int Max=-inf;
    int rs=0;
    fto(i,1,n) {cin>>a[i];Max=max(Max,abs(a[i]));}
    sort(a+1,a+1+n);
    vector<int> dg,am;
    dg.push_back(0);
    am.push_back(0);
    fto(i,1,n) if(a[i]>0) dg.push_back(a[i]);
    fdo(i,n,1) if(a[i]<0) am.push_back(abs(a[i]));
    if(dg.size()) {
        dp[0]=0;
        fto(i,1,dg.size()-1) {
            dp[i]=dp[max(i-k,0ll)]+dg[i]*2;
        }
        rs+=dp[dg.size()-1];
    }
    if(am.size()) {
        dp[0]=0;
        fto(i,1,am.size()-1) {
            dp[i]=dp[max(i-k,0ll)]+am[i]*2;
        }
        rs+=dp[am.size()-1];
    }
    if(rs) rs-=Max;
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
    Solve();
  }

  return 0;
}