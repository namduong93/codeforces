/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: O(logN)
 *    tested: 0s
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

const int N=1000005;
const int inf=1e9;

struct ndv {
  int l,r,w;
  bool operator < (const ndv &a) {
    return w<a.w;
  }
} a[N];
int n,m;
struct SegementTree {
    int n;
    vector<int> Sum;
    vector<int> lz;
    void init(int _n) {
      n=_n;
      Sum.resize(n*4+1);
      lz.resize(n*4+1);
    }
    void build(int x,int l,int r) {
      if(l==r) {Sum[x]=0;return ;}
      build(x*2,l,(l+r)/2);
      build(x*2+1,(l+r)/2+1,r);
      Sum[x]=min(Sum[x*2],Sum[x*2+1]);
    }

    void pushdown(int x,int l,int r) {
      if(lz[x]) {
        //if(x==15) cout<<"cc";
        Sum[x]+=lz[x];
        if(l<r) {
          lz[x*2]+=lz[x];
          lz[x*2+1]+=lz[x];
        }
        lz[x]=0;
      }
    }

    void upd(int x,int l,int r,int d,int c,int val) {
      //if(x==28) cout<<l<<' '<<r;
      pushdown(x,l,r);
      if(r<d||c<l) return ;
      if(d<=l&&r<=c) {
        lz[x]+=val;
        pushdown(x,l,r);
        return ;
      }
      upd(x*2,l,(l+r)/2,d,c,val);
      upd(x*2+1,(l+r)/2+1,r,d,c,val);
      Sum[x]=min(Sum[x*2],Sum[x*2+1]);
    }
    void upd(int d,int c,int val) {
      upd(1,1,n,d,c,val);
    }

    int get_Sum(int x,int l,int r,int d,int c) {
      pushdown(x,l,r);
      if(r<d||c<l) return inf;
      if(d<=l&&r<=c) return Sum[x];
      return min(get_Sum(x*2,l,(l+r)/2,d,c),get_Sum(x*2+1,(l+r)/2+1,r,d,c));
    }
    int get_Sum(int d,int c) {
      return get_Sum(1,1,n,d,c);
    }
};
SegementTree seg;
void Input() {
    cin>>n>>m;
    fto(i,1,n) cin>>a[i].l>>a[i].r>>a[i].w;
    a[0].w=-10000000;
}
void Solve() {
  sort(a+1,a+1+n);
  int tt=1;
  int rs=inf;
  seg.init(m);
  fto(i,1,n) {
    while(tt<=n&&!seg.get_Sum(2,m)) {
      seg.upd(a[tt].l+1,a[tt].r,1);
      tt++;
      if (seg.get_Sum(2,m)) {
				rs=min(rs,a[tt-1].w-a[i].w);
				break;
			}
    }
    if(seg.get_Sum(2,m)) {
      rs=min(rs,a[tt-1].w-a[i].w);
    }
    seg.upd(a[i].l+1,a[i].r,-1);
  }
  cout<<rs;
}
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  Input();
  Solve();
}