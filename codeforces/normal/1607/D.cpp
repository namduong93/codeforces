/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
**/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
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
const int N=200005;
const int inf =1000000000;

int n;
pii a[N];
string st;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i].fi;
    cin>>st;
    st=' '+st;
}
stack<int> sta1,sta2;
void Solve() {
    while(!sta1.empty()) sta1.pop();
    while(!sta2.empty()) sta2.pop();
    fto(i,1,n) {
        if(st[i]=='R') a[i].se=1;
        else a[i].se=-1;
    }
    sort(a+1,a+1+n);
    fdo(i,n,1) {
        if(a[i].se==-1) {
            sta1.push(a[i].fi);
        }
        else sta2.push(a[i].fi);
    }
    fto(i,1,n) {
        if(!sta1.empty()) {
            if(sta1.top()>=i){
                sta1.pop();
                continue;
            }
        }
        if(!sta2.empty()) {
            if(sta2.top()<=i) {
                //if(i==4) cout<<sta2.top();
                sta2.pop();
                continue;
            }
        }
        cout<<"NO"<<'\n';return ;
    }
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