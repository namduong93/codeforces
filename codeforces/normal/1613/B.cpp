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
const int N=1e6+5;
const int inf =1e9+7;

int n,a[N];
string st;
bool m[N];
void Solve() {
    cin>>n;
    fto(i,1,n) 
    {
        cin>>a[i];
        m[a[i]]=true;
    }
    sort(a+1,a+1+n);
    int cnt=0;
    fdo(i,n,2) {
        if(cnt==n/2) break;
        fdo(j,1,1) {
            if(cnt==n/2) break;
            if(!m[a[i]%a[j]])
            {
                cnt++;
                cout<<a[i]<<' '<<a[j]<<'\n';
            }
        }
    }
    fto(i,1,n) {
        m[a[i]]=false;
    }
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