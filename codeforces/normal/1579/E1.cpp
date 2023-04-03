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

const int N=200005;
const int inf =1000000000;
int n,a[N];
string st;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
}
deque<int> dq;
void Solve() {
  dq.push_back(a[1]);
  fto(i,2,n) {
    if(a[i]<=*dq.begin()) 
      dq.push_front(a[i]);
    else dq.push_back(a[i]);
  }
  while(!dq.empty()){
    cout<<dq.front()<<' ';
    dq.pop_front();
  }
  cout<<'\n';
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