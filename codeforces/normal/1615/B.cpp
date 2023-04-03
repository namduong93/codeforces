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
int getbit(int x,int i) {
    return x&(1<<i);
}
int cnt[N][40];
void Solve() {
    int l,r;
    int rs=0;
    cin>>l>>r;
    fto(j,0,30) rs=max(rs,cnt[r][j]-cnt[l-1][j]);
    cout<<r-l+1-rs<<'\n';
}
int32_t main() {
    if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fto(i,1,200000) {
        fto(j,0,30) {
            if(getbit(i,j)) cnt[i][j]=cnt[i-1][j]+1;
            else cnt[i][j]=cnt[i-1][j];
        }
    }
    int Test;
    cin>>Test;
    fto(iTest,1,Test) {
        Solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}