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

const int N=500;

int n,k;
pii chord[N];
void Input() {
  cin>>n>>k;
  fto(i,1,k) {
    cin>>chord[i].fi>>chord[i].se;
    if(chord[i].fi>chord[i].se) swap(chord[i].fi,chord[i].se);
  }
}
bool Boo[N];
vector<int> s[3];
void Solve() {
  fto(i,1,2*n) Boo[i]=false;
  fto(i,1,k) {
    Boo[chord[i].fi]=true;
    Boo[chord[i].se]=true;
  }
  int d=1;
  s[1].clear();s[2].clear();
  fto(i,1,2*n) if(!Boo[i]){
    s[d].push_back(i);
    if(s[d].size()==n-k) d++;
  }
  fto(i,k+1,n) {
    chord[i].fi=s[1][i-k-1];
    chord[i].se=s[2][i-k-1];
  }
  //fto(i,1,n) cout<<chord[i].fi<<' '<<chord[i].se<<'\n';
  int rs=0;
  fto(i,1,n)
  fto(j,1,n) {
    //if(i==2&&j==1) cout<<chord[j].fi;
    if(i!=j)
    if(chord[i].fi<chord[j].fi&&chord[j].fi<chord[i].se&&chord[i].se<chord[j].se)
    rs++;
  }
  cout<<rs<<'\n';
}
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