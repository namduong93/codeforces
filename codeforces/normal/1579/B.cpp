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

const int N=100005;
const int inf =1000000000;
int n,a[N],b[N];
string st;
void Input() {
	cin>>n;
	fto(i,1,n) cin>>a[i];	
}
vector<pii> rs;

void Solve() {
	int pos,kq;
	kq=0;
	rs.clear();
	fto(i,1,n) {
		pos =i;
		fto(j,i+1,n) if(a[j]<a[pos]) pos=j;
		if(pos==i) continue;
		rs.pb({i,pos});
		fdo(j,pos-1,i) a[j+1] = a[j];
	}
	cout<<rs.size()<<'\n';
	if(rs.size())
	fto(i,0,rs.size()-1) cout<<rs[i].fi<<' '<<rs[i].se<<' '<<rs[i].se-rs[i].fi<<'\n';
	//fto(i,1,n) cout<<a[i];
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