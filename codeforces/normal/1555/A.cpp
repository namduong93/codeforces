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
#define SZ(x) ((int)(x).size())

const int N=100005;

int n;
void Input() {
  cin>>n;
}
void Solve() {
  if(n<=6) {cout<<15<<'\n';return;}
  if(n%2==1) n++;
  int tt=n/6;
  int cl=n-tt*6;
  int rs=tt*15;
  if(cl==4) cout<<rs-15+25<<'\n';
  if(cl==2) cout<<rs-15+20<<'\n';
  if(cl==0) cout<<rs<<'\n';
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