/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
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

int n;
pair < pii , int > a[N];
string st;
int ans[N];
int c[N],b[N];
void Solve() {
  cin>>n;
  fto(i,1,n) {
    cin>>a[i].fi.fi;
    a[i].se=i;
    ans[i]=0;
  }
  fto(i,1,n) cin>>a[i].fi.se;
  sort(a+1,a+1+n);
  b[0]=-inf;
  c[n+1]=inf;
  fto(i,1,n) b[i]=max(b[i-1],a[i].fi.se);
  fdo(i,n,1) c[i]=min(c[i+1],a[i].fi.se);
  ans[n]=1;
  fdo(i,n-1,1) {
    int idx=lower_bound(c+1,c+1+n,b[i])-c - 1;
    //if(i==n-1) cout<<c[idx+1]<<' ';
    if(idx>i) {
      ans[i]=ans[idx];
    }
  }
  st.resize(n);
  fto(i,1,n) {
    st[a[i].se-1]=ans[i]+'0';
  }
  cout<<st<<'\n';
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