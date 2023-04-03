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

const int N=50005;

int n;
int r[N][6];
int M[7];
void Input() {
  cin>>n;
  fto(i,1,n) fto(j,1,5) cin>>r[i][j];
}
void Solve() {
  if(n==1) {cout<<1<<'\n';return;}
  int kq=0;
  fto(j,1,5) M[j]=r[1][j]; M[6]=1;
  fto(i,2,n)
  {
    int dem=0;
    fto(j,1,5) {
      if(r[i][j]<M[j]) dem++;
    }
    if(dem>=3) {
      fto(j,1,5) M[j]=r[i][j];
      M[6]=i;
    }
  }
  fto(i,1,n) {
    if(i==M[6]) continue;
    int dem=0;
    fto(j,1,5)
    if(r[M[6]][j]<r[i][j]) dem++;
    if(dem<3) {cout<<-1<<'\n';return;}
  }
  cout<<M[6]<<'\n';
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