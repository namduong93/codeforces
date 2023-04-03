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
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;

const int mod=998244353;
const int N=10;
const long long inf =1000000000000000;

int n,a[N];
string st;
int x;
void Input() {
    cin>>x>>n;
}
void Solve() {
    a[0]=x;
    fto(i,1,4) {
        if((a[i-1]+inf)%2==0)
        a[i]=a[i-1]-i;
        else a[i]=a[i-1]+i;
    }
    if(n<=4) {cout<<a[n]<<'\n';return ;}
    if(n%4==1) {
        if((a[1]+inf)%2==0)
        cout<<a[1]+(n/4)*4<<'\n';
        else cout<<a[1]-(n/4)*4<<'\n';
    }
    if(n%2==0) {
        if(n%4==2)
        cout<<a[2]<<'\n';
        else cout<<a[4]<<'\n';
    }
    if(n%4==3) {
        if((a[1]+inf)%2==0)
        cout<<a[3]-(n/4)*4<<'\n';
        else cout<<a[3]+(n/4)*4<<'\n';
    }
    //cout<<'\n';*/
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