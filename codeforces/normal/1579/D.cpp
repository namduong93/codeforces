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
#define pii pair<int,int>
#define mod 998244353
#define SZ(x) ((int)(x).size())
priority_queue<pii> pq;

const int N=200005;
const int inf =1000000000;
int n,a[N];
string st;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
}
pii x[3];
vector<pii> rs;
void Solve() {
  rs.clear();
  while(!pq.empty()) pq.pop();
  fto(i,1,n) if(a[i]!=0) pq.push({a[i],i});
  while(!pq.empty()) {
    x[1]=pq.top();
    pq.pop();
    if(pq.empty()) break;
    x[2]= pq.top();
    pq.pop();
    rs.push_back({x[1].se,x[2].se});
    x[1].fi--;
    x[2].fi--;
    if(x[1].fi!=0) pq.push(x[1]);
    if(x[2].fi!=0) pq.push(x[2]);
  }
  cout<<rs.size()<<'\n';
  if(rs.size()) 
    fto(i,0,rs.size()-1) cout<<rs[i].fi<<' '<<rs[i].se<<'\n';
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