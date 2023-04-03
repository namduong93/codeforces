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
string rm(string gg) {
    while(1) {
        bool stop=false;
        if(gg.find("AA")!=gg.npos) {
            gg.erase(gg.find("AA"),2);
            stop=true;
            continue;
        }
        if(gg.find("CC")!=gg.npos) {
            gg.erase(gg.find("CC"),2);
            stop=true;
        }
        if(!stop) return gg;
    }
    return gg;
}
string u,v;
string uu,vv;
void Solve() {
    cin>>u>>v;
    uu=vv="";
    int cntB=0;
    fto(i,0,u.length()-1) if(u[i]!='B') {
        uu+=u[i];
    }
    else cntB++;
    fto(i,0,v.length()-1) if(v[i]!='B') {
        vv+=v[i];
    }
    else cntB--;
    if(abs(cntB)%2==1) {cout<<"NO"<<'\n';return;}
    if(rm(uu)==rm(vv)) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
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