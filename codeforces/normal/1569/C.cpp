/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    dmm fermat, dac biet la thang nho
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

const int N=200005;
const int inf =1000000000;
int n,a[N];
string st;
int fact[N];
int Max;
void Input() {
  Max=0;
  cin>>n;
  fto(i,1,n) {
    cin>>a[i];
    Max=max(Max,a[i]);
  }
}
int Pow(int aa,int bb) {
  if(bb==0) return 1;
  aa=aa%mod;
  if(bb==1) return aa;
  int cc=Pow(aa,bb/2);
  cc=(cc*cc)%mod;
  if(bb&1) return (cc*aa)%mod;
  return cc;
}
int nPk(int nn,int kk) {
  return (fact[nn]*Pow(fact[nn-kk],mod-2))%mod;
}
void Solve() {
  int d1,d2;
  d1=d2=0;
  int kq=fact[n];
  fto(i,1,n) {
    if(a[i]==Max) d1++;
    if(a[i]==Max-1) d2++;
  }
  if(d1>1) {cout<<fact[n]<<'\n';return ;}
  fto(i,1,n) {
    if(i-1<d2) continue;
    int cc=(nPk(i-1,d2)*fact[n-d2-1])%mod;
    kq=(kq+mod-cc)%mod;
  }
  cout<<kq<<'\n';
}
#undef int
int main() {
  #define int long long
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fact[0]=1;;
  fto(i,1,200000) fact[i]=(fact[i-1]*i)%mod;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}