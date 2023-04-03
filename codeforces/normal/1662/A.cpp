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
const int N=2005;
const int inf =1e9+7;

int n;
pii a[N];
string st;
int d[11];
void Solve() {
    cin>>n;
    fto(i,1,n) cin>>a[i].fi>>a[i].se;
    fto(i,0,10) d[i]=-1;
    fto(i,1,n) {
        d[a[i].se]=max(d[a[i].se],a[i].fi);
    }
    fto(i,1,10) if(d[i]==-1) {
        cout<<"MOREPROBLEMS"<<'\n';
        return ;
    }
    int rs=0;
    fto(i,1,10) rs+=d[i];
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