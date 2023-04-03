/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int n;
vector<int> a[N];
string st;
priority_queue <pii, vector<pii>, greater<pii>> dHeap;
set<int> s;

int dp[N];
bool Tham[N];

void dfs(int u) {
    Tham[u]=true;
    int cnt=0;
    fto(i,0,a[u].size()-1) {
        int v=a[u][i];
        if(!Tham[v]) cnt++;
    }
    if(cnt!=0) {
        fto(i,0,a[u].size()-1) {
            int v=a[u][i];
            if(!Tham[v])
            {
                dfs(v);
                dp[u]+=dp[v];
            }
        }
        if(dp[u]==0) dp[u]=1;
        else dp[u]=dp[u]-1;
    }
    else {
        dp[u]=1;
    }
}
void Solve() {
    cin>>n;
    if(n==1) {cout<<"Alice";return;}
    fto(i,1,n) {Tham[i]=false;dp[i]=0;}
    fto(i,1,n-1) {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    if(dp[1]) cout<<"Alice"<<'\n';
    else cout<<"Bob"<<'\n';
}

int32_t main() {

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int Test;
    Test=1;
    fto (iTest,1,Test) {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}