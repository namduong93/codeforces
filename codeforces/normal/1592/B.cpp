/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
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
const int inf =1000000000;
int n,a[N],x;
string st;
vector<int> rr;
void Input() {
  cin>>n>>x;
  fto(i,1,n) cin>>a[i];
}
void rrh() {
  rr.clear();
  fto(i,1,n) rr.push_back(a[i]);
  sort(rr.begin(),rr.end());
  //rr.resize(unique(rr.begin(),rr.end())-rr.begin());
  fto(i,1,n) a[i]=lower_bound(rr.begin(),rr.end(),a[i])-rr.begin()+1;
}
int cnt[N];
void Solve() {
  fto(i,1,n) cnt[i]=0;
  rrh();
  int Boo=1;
  fto(i,1,n) cnt[a[i]]++;
  fto(i,1,n)
  {
    //cout<<a[i]<<' '<<cnt[a[i]]<<' ';
    if(a[i]<=i&&i<=a[i]+cnt[a[i]]-1) continue;
    if (i-x<=0&&i+x>n) Boo = 0;
  }
  if(Boo)cout << "YES\n";
  else cout << "NO\n";
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