/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
**/
#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;i=i-2)
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
int n,a[N],b[N];
int pos[N];
string st;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
  fto(i,1,n) cin>>b[i];
}
void Solve() {
  int kq=inf;
  fto(i,1,n) pos[b[i]]=i;

  fdo(i,n*2-2,1)
  pos[i]=min(pos[i],pos[i+2]);

  fto(i,1,n) {
    kq=min(kq,i-2+pos[a[i]+1]);
  }
  cout<<kq<<'\n';
}
int32_t main() {
  //freopen("test.inp","r",stdin);
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