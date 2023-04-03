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

const int N=100005;

int H,W;
int x,y,x2,y2;
int w,h;
void Input() {
  cin>>W>>H;
  cin>>x>>y>>x2>>y2;
  cin>>w>>h;
}
void Solve() {
  int rs=1000000000;
  if(max(w-x,0)+x2<=W) rs=min(rs,max(w-x,0));
  if(max(h-y,0)+y2<=H) rs=min(rs,max(h-y,0));
  if(max(w-(W-x2),0)<=x) rs=min(rs,max(w-(W-x2),0));
  //cout<<rs;
  if(max(h-(H-y2),0)<=y) rs=min(rs,max(h-(H-y2),0));
  if(rs!=1000000000)
  cout<<rs<<".000000000"<<'\n';
  else cout<<-1<<'\n';
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