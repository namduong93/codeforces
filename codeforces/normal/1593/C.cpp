/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
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
 
const int N=400005;
const int inf =1000000000;
int n,a[N],k;
string st;
int x[N];
void Input() {
    cin>>n>>k;
    fto(i,1,k) cin>>x[i];
    sort(x+1,x+1+k);
}
void Solve() {
    int sum=0;
    fdo(i,k,1){
        if(sum+n-x[i]<n){
            sum+=n-x[i];
        }
        else {cout<<k-i<<'\n';return ;}
    }
    cout<<k<<'\n';
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