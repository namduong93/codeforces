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

int n,a[105];
string st;
int h;
bool check(int m) {
    int tmp=0;
    a[n+1]=a[n]+m;
    fto(i,1,n) {
        tmp=tmp+min(a[i+1]-a[i],m);
    }
    if(tmp>=h) return true;
    return false;
}
void Solve() {
    cin>>n>>h;
    fto(i,1,n) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int d=1;
    int c=1e18;
    int rs=1e18;
    while(d<=c) {
        int mid=(d+c)/2;
        if(check(mid)) {
            rs=mid;
            c=mid-1;
        }
        else d=mid+1;
    }
    cout<<rs<<'\n';
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