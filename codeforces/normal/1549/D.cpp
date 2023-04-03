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
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define mod 998244353
#define inf 0
#define SZ(x) ((int)(x).size())

const int N=200005;

int a[N],b[N];
int GCD(int a,int b) {
  if(b==0) return a;
  if(a==0) return b;
  return __gcd(a,b);
}
struct SegementTree {
    int n;
    vector<int> IT;
    vector<int> lz;
    void init(int _n) {
      n=_n;
      IT.resize(n*4+1);
      lz.resize(n*4+1);
    }
    void build(int x,int l,int r) {
      if(l==r) {IT[x]=b[l];return ;}
      build(x*2,l,(l+r)/2);
      build(x*2+1,(l+r)/2+1,r);
      IT[x]=GCD(IT[x*2],IT[x*2+1]);
    }

    void pushdown(int x,int l,int r) {
      if(lz[x]) {
        IT[x]+=lz[x];
        if(l<r) {
          lz[x*2]+=lz[x];
          lz[x*2+1]+=lz[x];
        }
        lz[x]=0;
      }
    }

    void upd(int x,int l,int r,int d,int c,int val) {
      pushdown(x,l,r);
      if(r<d||c<l) return ;
      if(d<=l&&r<=c) {
        lz[x]+=val;
        pushdown(x,l,r);
        return ;
      }
      upd(x*2,l,(l+r)/2,d,c,val);
      upd(x*2+1,(l+r)/2+1,r,d,c,val);
      IT[x]=GCD(IT[x*2],IT[x*2+1]);
    }
    void upd(int d,int c,int val) {
      upd(1,1,n,d,c,val);
    }

    int get_IT(int x,int l,int r,int d,int c) {
      pushdown(x,l,r);
      if(r<d||c<l) return inf;
      if(d<=l&&r<=c) return IT[x];
      return GCD(get_IT(x*2,l,(l+r)/2,d,c),get_IT(x*2+1,(l+r)/2+1,r,d,c));
    }
    int get_IT(int d,int c) {
      return get_IT(1,1,n,d,c);
    }
}seg;

int n;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
}
void Solve() {
  if(n==1) {
    cout<<1<<'\n';
    return ;
  }
  n--;
  fto(i,1,n) {
    b[i]=abs(a[i]-a[i+1]);
  }
  seg.init(n);
  seg.build(1,1,n);
  int rs=1;
  int l=1;
  fto(i,1,n) {
    while(l<i&&seg.get_IT(l,i)==1ll) l++;
    if(seg.get_IT(l,i)!=1ll) rs=max(rs,i-l+2);
  }
  cout<<rs<<'\n';
}
#undef int
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}