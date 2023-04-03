/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;
typedef long long ll;

const int mod=998244353;
const int N=200005;
const int inf =1e9+7;

int n,a[N];
string st;
void Solve() {
    cin>>n;
    int h=1;
    fto(i,1,n) cin>>a[i];
    fto(i,1,n) {
        if(a[i]==0) {
            if(i!=1&&a[i-1]==0) {cout<<-1<<'\n';return;}
        }
        if(a[i]==1) {
            if(i!=1&&a[i-1]==1) {h+=5;continue;}
            if(i!=1&&a[i-1]==0) {h+=1;continue;}
            h+=1;
        }
    }
    cout<<h<<'\n';
    return ;
}
int32_t main() {
  if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Solve();
  }

  return 0;
}