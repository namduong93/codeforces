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

const int N=600005;
struct ndv {
  int pos,l,r;
  bool operator < (const ndv &gg) const {
    return pos<gg.pos;
  }
}a[N];
//---------------------------------
struct SegementTree {
    int n;
    vector<pii> Max;
    vector<pii> lz;
    void init(int _n) {
      n=_n;
      Max.resize(n*4+1);
      lz.resize(n*4+1);
    }

    void pushdown(int x,int l,int r) {
      if(lz[x].fi) {
        Max[x]=max(Max[x],lz[x]);
        if(l<r) {
          lz[x*2]=max(lz[x*2],lz[x]);
          lz[x*2+1]=max(lz[x*2+1],lz[x]);
        }
        lz[x]={0,0};
      }
    }

    void upd(int x,int l,int r,int d,int c,pii val) {
      pushdown(x,l,r);
      if(r<d||c<l) return ;
      if(d<=l&&r<=c) {
        lz[x]=max(lz[x],val);
        pushdown(x,l,r);
        return ;
      }
      upd(x*2,l,(l+r)/2,d,c,val);
      upd(x*2+1,(l+r)/2+1,r,d,c,val);
      Max[x]=max(Max[x*2],Max[x*2+1]);
    }
    void upd(int d,int c,pii val) {
      upd(1,1,n,d,c,val);
    }

    pii get_Max(int x,int l,int r,int d,int c) {
      pushdown(x,l,r);
      if(r<d||c<l) return {0,0};
      if(d<=l&&r<=c) return Max[x];
      return max(get_Max(x*2,l,(l+r)/2,d,c),get_Max(x*2+1,(l+r)/2+1,r,d,c));
    }
    pii get_Max(int d,int c) {
      return get_Max(1,1,n,d,c);
    }
}seg;
//------------------------------------
int n,m;
int tt;
void Input() {
  cin>>n>>m;
  tt=n+1;
  fto(i,1,m) {
    cin>>a[i].pos>>a[i].l>>a[i].r;
  }
  tt=1;
}
vector<int> s;
void rrh() {
  fto(i,1,m) {s.push_back(a[i].l);s.push_back(a[i].r);}
  sort(s.begin(),s.end());
  s.resize(unique(s.begin(),s.end())-s.begin());
  fto(i,1,m) {
    a[i].l=lower_bound(s.begin(),s.end(),a[i].l)-s.begin()+1;
    a[i].r=lower_bound(s.begin(),s.end(),a[i].r)-s.begin()+1;
  }
}
pii F[N];
bool Boo[N];
pii rs;
void Solve() {
  rrh();
  sort(a+1,a+1+m);
  seg.init(2*m);
  fto(i,1,m) {
    if(a[i].pos!=a[tt].pos) {
      fto(j,tt,i-1) seg.upd(a[j].l,a[j].r,make_pair(F[a[tt].pos].first,a[tt].pos) );
      tt=i;
    }
    pii cc=seg.get_Max(a[i].l,a[i].r);
    F[a[i].pos]=max(F[a[i].pos],make_pair(cc.first+1,cc.second));
  }
  int tmp=0;
  fto(i,1,n) {
    if(rs<F[i]) {
      rs=max(rs,F[i]);
      tmp=i;
    }
  }
  Boo[tmp]=true;
  cout<<n-rs.first<<'\n';
  if(rs.first==0) return ;
  while(rs.first!=0) {
    Boo[rs.second]=true;
    rs=F[rs.second];
  }
  fto(i,1,n) {
    if(!Boo[i]) cout<<i<<' ';
  }
}
int main() {
  //freopen("test.inp","r",stdin);
  //freopen("test.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  Test=1;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}