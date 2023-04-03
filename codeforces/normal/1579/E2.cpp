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
int IT[2][N*4];
int get(int ch,int x,int l,int r,int d,int c) {
  if(r<d||c<l) return 0;
  if(d<=l&&r<=c) return IT[ch][x];
  return get(ch,x*2,l,(l+r)/2,d,c)+get(ch,x*2+1,(l+r)/2+1,r,d,c);
}
void update(int ch,int x,int l,int r,int u,int val) {
  if (r<u||u<l) return ;
  if(u==l&&u==r) {IT[ch][x]+=val;return ;}
  update(ch,x*2,l,(l+r)/2,u,val);
  update(ch,x*2+1,(l+r)/2+1,r,u,val);
  IT[ch][x]=IT[ch][x*2]+IT[ch][x*2+1];
}
vector<int> rr;
void rrh() {
  rr.clear();
  fto(i,1,n) rr.push_back(a[i]);
  sort(rr.begin(),rr.end());
  rr.resize(unique(rr.begin(),rr.end())-rr.begin());
  fto(i,1,n) a[i]=lower_bound(rr.begin(),rr.end(),a[i]) - rr.begin()+1;
}
void Solve() {
  rrh();
  int kq=0;
  fto(i,1,4*n) IT[0][i]=0;
  fto(i,1,n) {
    int tt1,tt2;
    tt1=0;
    tt2=0;
    tt1+=get(0,1,1,n,1,a[i]-1);
    tt2+=get(0,1,1,n,a[i]+1,n);
    kq+=min(tt1,tt2);
    update(0,1,1,n,a[i],1);
  }
  cout<<kq<<'\n';
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