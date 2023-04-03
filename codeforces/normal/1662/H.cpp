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

int n;
string st;
void Solve() {
    int w,l;
    vector<int>s;
    cin>>w>>l;

    int a=__gcd(w-2,l);
    fto(i,1,sqrt(a)) {
        if(a%i==0) {s.push_back(i);s.push_back(a/i);}
    }
     a=__gcd(w,l-2);
    fto(i,1,sqrt(a)) {
        if(a%i==0) {s.push_back(i);s.push_back(a/i);}
    }
     a=__gcd(w-1,l-1);
    fto(i,1,sqrt(a)) {
        if(a%i==0) {s.push_back(i);s.push_back(a/i);}
    }
    s.push_back(2);
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());

    cout<<s.size()<<' ';
    if(s.size())
    fto(i,0,s.size()-1) {
        cout<<s[i]<<' ';
    }
    cout<<'\n';
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