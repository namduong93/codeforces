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
const int inf =1000000000;
int n,a[N];
string st;
void Input() {
  cin>>n;
  cin>>st;
  st=' '+st;
}
int F[55];
void Solve() {

  fto(i,1,n) {
  if(st[i]=='a') F[i]=F[i-1]+1;
  else F[i]=F[i-1]-1;
  }

  fto(i,1,n)
  fto(j,i,n) {
  if(F[j]-F[i-1]==0) {cout<<i<<' '<<j<<'\n';return ;}
  }
  cout<<-1<<' '<<-1<<'\n';
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