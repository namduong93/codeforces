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
int n,m;
string st;
int F[N][4][4];
void Input() {
  cin>>n>>m;
  cin>>st;
  st=' '+st;
}
void Solve() {
  F[n+1][2][1]=F[n+1][2][0]=0;
  F[n+1][1][0]=F[n+1][1][2]=0;
  F[n+1][0][1]=F[n+1][0][2]=0;
  fdo(i,n,1) {
    fto(tt1,0,2)
    fto(tt2,0,2) {
      if(tt1==tt2) continue;
      int tt3=0;
      if(tt3==tt1) tt3++;
      if(tt3==tt2) tt3++;
      if(tt3==tt1) tt3++;
      F[i][tt1][tt2]=F[i+1][tt2][tt3]+1-(st[i]-'a'==tt1);
    }
  }
  fto(i,1,m){
    int l,r;
    cin>>l>>r;
    int len=r-l+1;
    int rs=200005;
    if(len==2) {cout<<(st[r]==st[l])<<'\n';continue;}
    if(len==1) {cout<<0<<'\n';continue;}
    fto(tt1,0,2)
    fto(tt2,0,2) {
      if(tt1==tt2) continue;
      int tt3=0;
      if(tt3==tt1) tt3++;
      if(tt3==tt2) tt3++;
      if(tt3==tt1) tt3++;

      int x,y;
      if(len%3==0) {x=tt1;y=tt2;}
      if(len%3==1) {x=tt2;y=tt3;}
      if(len%3==2) {x=tt3;y=tt1;}
      rs=min(rs,F[l][tt1][tt2]-F[r+1][x][y]);
    }
    cout<<rs<<'\n';
  }
}
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  Test=1;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}