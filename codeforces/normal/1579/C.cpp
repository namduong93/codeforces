/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
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

const int N=30;
const int inf =1000000000;
int n,a[N];
string st;
int m,k;
char ch[N][N];
bool Boo[N][N];
void Input() {
  cin>>n>>m>>k;
  fto(i,1,n) {
    cin>>st;
    fto(j,1,m) ch[i][j]=st[j-1];
  }
}
void Solve() {
  fto(i,1,n) fto(j,1,m) Boo[i][j]=false;
  fto(i,1,n)
  fto(j,1,m) if(ch[i][j]=='*') {
    int tmp=0;
    while(1) {
      if(i-tmp<1||j+tmp>m||j-tmp<1) break;
      if(ch[i-tmp][j+tmp]=='*'&&ch[i-tmp][j-tmp]=='*') tmp++;
      else break;
    }
    //if(i==3&&j==3) cout<<tmp<<k;
    if(tmp-1>=k)
      fto(cc,0,tmp-1) Boo[i-cc][j+cc]=Boo[i-cc][j-cc]=true;
        //Bif(i==3&&j==3) cout<<tmp<<k<<Boo[3][3];
  }
  fto(i,1,n) fto(j,1,m) if(ch[i][j]=='*'&&!Boo[i][j]) {cout<<"NO"<<'\n';return;}
  cout<<"YES"<<'\n';
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