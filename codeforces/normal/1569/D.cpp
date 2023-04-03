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

const int N=200005;
const int M=1000005;
const int inf =1000000000;
int a[2],k;
int st;
long long kq;
int x[2][N];
bool blx[M],bly[M];
vector<pii> s[2];
int IT[4*M];
void Input() {
  kq=0;
  fto(i,0,1000000) blx[i]=bly[i]=false;
  s[0].clear();
  s[1].clear();
  cin>>a[0]>>a[1]>>k;
  fto(i,1,a[0]) {cin>>x[0][i];blx[x[0][i]]=true;}
  fto(i,1,a[1]) {cin>>x[1][i];bly[x[1][i]]=true;}
  fto(i,1,k) {
    int u,v;
    cin>>u>>v;
    if(blx[u]&&bly[v]) continue;
    if(blx[u]) s[0].push_back({u,v});
    else s[1].push_back({v,u});
  }
}
int bs1(int xx,int pos) {
  int d,c;
  d=1;c=a[pos];
  int rs=-1;
  while(d<=c) {
    int mid=(d+c)/2;
    if(x[pos][mid]<=xx) {rs=mid;d=mid+1;}
    else c=mid-1;
  }
  return rs;
}
int bs2(int xx,int pos) {
  int d,c;
  d=1;c=a[pos];
  int rs=-1;
  while(d<=c) {
    int mid=(d+c)/2;
    if(x[pos][mid]>=xx) {rs=mid;c=mid-1;}
    else d=mid+1;
  }
  return rs;
}
int get(int x,int l,int r,int d,int c) {
  if(r<d||c<l) return 0;
  if(d<=l&&r<=c) return IT[x];
  return get(x*2,l,(l+r)/2,d,c)+get(x*2+1,(l+r)/2+1,r,d,c);
}
void upd(int x,int l,int r,int u,int val) {
  if(u==l&&u==r) {if(val==0) IT[x]=0; else IT[x]+=val;return ;}
  if(u<l||r<u) return ;
  upd(x*2,l,(l+r)/2,u,val);
  upd(x*2+1,(l+r)/2+1,r,u,val);
  IT[x]=IT[x*2]+IT[x*2+1];
}
bool conv( pii aa, pii bb) {
  if(aa.fi!=bb.fi) return (aa<bb);
  return (aa.se>bb.se);
}
void Solve() {

  if(s[0].size())
  sort(s[0].begin(),s[0].end());
  if(s[1].size())
  sort(s[1].begin(),s[1].end());

  int tmp=0;
  while(1)
  {
    //fto(i,0,4000000) IT[i]=0;
    if(s[tmp].size())
    {
      fto(i,0,s[tmp].size()-1) {
        if(i==0) st=0;
        else {
          if(s[tmp][i].fi!=s[tmp][i-1].fi)
          {
            //if(tmp==1) cout<<i;
            fto(j,st,i-1)
            {
              upd(1,0,1000000,s[tmp][j].se,1);
            }
            //cout<<'\n';
            st=i;
          }
        }
        int down=bs1(s[tmp][i].se,1-tmp);
        int upper=bs2(s[tmp][i].se,1-tmp);
        kq=kq+get(1,0,1000000,x[1-tmp][down],x[1-tmp][upper]);
      }
      fto(i,0,s[tmp].size()-1) upd(1,0,1000000,s[tmp][i].se,0);
    }
    tmp=1-tmp;
    if(tmp==0) break;
  }
  cout<<kq<<'\n';
}
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