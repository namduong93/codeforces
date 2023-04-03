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
#define ftof(i,a,b) for(int i=a;i<=b;i+=2)
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
  cin>>st;
}
void Solve() {
  
  n=st.length();
  int tt1=0;
  int tt2=0;
  ftof(i,0,n-1)
  tt1=tt1*10+st[i]-'0';
  ftof(i,1,n-1)
  tt2=tt2*10+st[i]-'0';
  cout<< 1LL*(tt1+1)*(tt2+1)-2;
  cout<<'\n';
}
#undef int
int main() {
 // freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}