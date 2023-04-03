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

int n,k,a[N];
void Input() {
  cin>>n>>k;
  fto(i,1,n) cin>>a[i];
}
int pos[N];
vector<int> s;
void rrh() {
  s.clear();
  fto(i,1,n) s.push_back(a[i]);
  sort(s.begin(),s.end());
  s.resize(unique(s.begin(),s.end())-s.begin());
  fto(i,1,n) a[i]=lower_bound(s.begin(),s.end(),a[i])-s.begin()+1;
  fto(i,1,n) pos[a[i]]=i;
  int tt=1;
  while(tt<=n) {
  //  cout<<tt;
    int tmp=pos[tt];
    while(tmp<n&&a[tmp]==a[tmp+1]-1) {
      tmp++;tt++;
    }
    tt++;
    k--;
  //  cout<<tt<<'\n';
  }
  if(k<0) cout<<"No"<<'\n';
  else cout<<"Yes"<<'\n';
}
void Solve() {
  if(n==1) {cout<<"YES"<<'\n';return ;}
  else
  rrh();
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