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
int n,k;
string st;
int x;
pair<int,int> can;
vector<int> a[N];
int v[N],Xor[N],vis[N];
void Input() {
	cin>>n>>k;
	fto(i,1,n) {cin>>v[i];if(i==1) x=v[1]; else x=x^v[i];a[i].clear();}
	fto(i,1,n-1) {
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}
bool Boo;
void dfs(int u) {
	if(Boo) return ;
	Xor[u]=v[u];
	if(a[u].size()) {
		fto(i,0,a[u].size()-1) {
			int v=a[u][i];
			//if(can==make_pair(4,5)&&u==1) cout<<i<<' ';
			if(vis[v]==0&&make_pair(u,v)!=can) {
				vis[v]=u;
				dfs(v);
				Xor[u]=Xor[u]^Xor[v];
			}
		}
	}
	if(Xor[u]==x&&u!=1) {can=make_pair(vis[u],u);Boo=true;}
	//if(u==4) cout<<can.fi<<' '<<can.se;
}
void Solve() {
	can=make_pair(-1,-1);
	fto(i,1,n) vis[i]=0;
 
	if(x==0) {cout<<"YES"<<'\n';return ;}
	if(k==2) {cout<<"NO"<<'\n';return ;}
	vis[1]=-1;
	Boo=false;
	dfs(1);
	if(can==make_pair(-1,-1)) {cout<<"NO"<<'\n';return;}
	pii cf=can;
 
	fto(i,1,n) vis[i]=0;
	vis[1]=-1;
	Boo=false;
	//cout<<a[1].size();
 
	dfs(1);
	if(can==cf) {cout<<"NO"<<'\n';return ;}
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