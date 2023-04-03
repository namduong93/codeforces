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
const int inf=1000000000;

int n,a[N];
string st;
int F[N][2],Pre[N][2];
void Input() {
  cin>>n;
  cin>>st;
  st=' '+st;
}
void Solve() {
  fto(i,0,n) fto(j,0,1) F[i][j]=inf;
  F[0][0]=F[0][1]=0;
  fto(i,1,n)
  fto(j,0,1) {

    if(st[i]=='R'||st[i]=='B') {
      if(st[i]=='R'&&j==1) continue;
      if(st[i]=='B'&&j==0) continue;
      fto(k,0,1) {
        if(F[i][j]>F[i-1][k]+(j==k))
        {
          F[i][j]=F[i-1][k]+(j==k);
          Pre[i][j]=k;
        }
      }
    }
    else {
      fto(k,0,1) {
        if(F[i][j]>F[i-1][k]+(j==k))
        {
          F[i][j]=F[i-1][k]+(j==k);
          Pre[i][j]=k;
        }
      }
    }
  }

  stack<char> sta;
  int cnt=-1;
  if(F[n][0]<F[n][1]) cnt=0; else cnt=1;

  fdo(i,n,1) {

    if(cnt==0)
    sta.push('R');
    if(cnt==1) sta.push('B');

    cnt=Pre[i][cnt];
  }
  while(!sta.empty()) {cout<<sta.top();sta.pop();}
  cout<<'\n';
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