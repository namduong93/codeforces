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
int a[N];
string st;
int pos[N];
int ans[N];
void Solve() {
    vector<int> s1,s2;
    fto(i,1,n) pos[i]=ans[i]=0;
  cin>>n;
int cnt = n;
  fto(i,1,n) {
      cin >> a[i]; 
      pos[a[i]] = i;
  }
  cin>>st;
  fto(i,1,n)
  {
    if(st[i-1]-'0') s1.pb(a[i]);
    else s2.pb(a[i]);
  }
  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());

  int t1 = s1.size();
  int t2=s2.size();

  fdo(i,t1-1,0) ans[pos[s1[i]]] = cnt--;
  fdo(i,t2-1,0) ans[pos[s2[i]]] = cnt--;
  fto(i,1,n) cout << ans[i]<<" "; cout << '\n';
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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}