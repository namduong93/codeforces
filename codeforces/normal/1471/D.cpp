/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
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

const int N=300005;
const int inf=1000000;
const int M=1000005;

int n,a[N];
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
}

int D[M];
void sieve() {
  fto(i,2,trunc(sqrt(inf))) if(!D[i]) {
    int j=i*i;
    while(j<=inf) {
      D[j]=i;
      j+=i;
    }
  }
  fto(i,1,inf) if(!D[i]) {
    D[i]=i;
  }
}

struct Compression {
  vector<pii> cps;
  map<int,int> cnt;
  void Clear() {
    if(cps.size()) cps.clear();
    cnt.clear();
  }
  void Do(int a[],int n) {
    fto(i,1,n) {
      cnt[a[i]]++;
    }
    fto(i,1,n) {
      cps.push_back(mp(a[i],cnt[a[i]]));
    }
    sort(cps.begin(),cps.end());
    cps.resize(unique(cps.begin(),cps.end())-cps.begin());
  }
} rr;
int cc[M];
void Solve() {
  fto(i,1,n) if(a[i]!=1) {
    int tmp1=a[i];
    while(D[tmp1]!=1) {
      cc[D[tmp1]]++;
      tmp1/=D[tmp1];
    }
    tmp1=a[i];
    int tmp2=1;
    while(D[tmp1]!=1) {
      int tmp3=D[tmp1];
      if(cc[tmp3]%2) {
        tmp2=tmp2*tmp3;
        cc[D[tmp1]]=0;
        while(tmp1%tmp3==0) tmp1=tmp1/tmp3;
      }
      else {
        cc[D[tmp1]]=0;
        while(tmp1%tmp3==0) tmp1=tmp1/tmp3;
      }
    }
    a[i]=tmp2;
  }
/*  fto(i,1,n) {
    cout<<a[i]<<' ';
  }*/

  int rs1,rs2;
  rs1=1;rs2=0;
  rr.Clear();
  rr.Do(a,n);
  fto(i,0,rr.cps.size()-1)
  rs1=max(rs1,rr.cps[i].se);
  fto(i,0,rr.cps.size()-1) {
    if(rr.cps[i].fi==1) {rs2+=rr.cps[i].se;continue;}
    if(rr.cps[i].se%2==0) rs2+=rr.cps[i].se;
  }
  int q;
  cin>>q;
  fto(i,1,q) {
    ll w; cin>>w;
    if(w==0ll) cout<<rs1<<'\n';
    else cout<<max(rs1,rs2)<<'\n';
  }
}
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  sieve();
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}