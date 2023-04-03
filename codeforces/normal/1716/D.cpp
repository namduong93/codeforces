/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

//#define int long long
#define fto(i,a,b) for(int i = a; i <= b; ++i)
#define fdo(i,a,b) for(int i = a; i >= b; --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())

int getBit (int x, int i) {return x & (1 << i);}
int turnBit (int x, int i) {return x | (1 << i);}
int swapBit (int x, int i) {return x ^ (1 << i);}
 
typedef pair <int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 200005;
const int inf = 1e9+7;

int n,k;
int a[N];
string st;
priority_queue <pii, vector<pii>, greater<pii>> dHeap;
set<int> s;

int res[N];
int dp[2][N];
void Solve() {
    cin>>n>>k;
    fto(i,1,n) if(i%k==0) {dp[0][i]=1;res[i]+=dp[0][i];}
    int sum=k;
    fto(i,k+1,n) {
        sum+=i;
        if(sum>n) break;
        fto(j,1,n) if(j>=i) {
            dp[1][j]=(dp[1][j]+dp[0][j-i])%mod;
            dp[1][j]=(dp[1][j]+dp[1][j-i])%mod;
        }
        fto(j,1,n) dp[0][j]=dp[1][j];
        fto(j,1,n) res[j]=(res[j]+dp[0][j])%mod;
        fto(j,1,n) dp[1][j]=0;
        //cout<<dp[0][2];
    }
    fto(i,1,n) cout<<res[i]<<' ';
}

int32_t main() {

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int Test = 1;
    //cin >> Test;
    fto (iTest,1,Test) {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}