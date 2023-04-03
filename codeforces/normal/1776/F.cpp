#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> Point;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define MOD 1000000007
#define MOD1 1000000009
#define sqr(x) sqr((x)*(x))

void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef BE_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

const int N = 100;

int n,m;
vector<pair<int,int> > edge[N];
bool visited[N];
int l,r;
int level[N];
queue<int> q;
int ans[100000];


void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        edge[i].clear();
        visited[i] = 0;
    }
    
    for(int i = 1 ; i <= m; i ++) {
        cin >> l >> r;
        if(m == n * (n - 1) / 2) {
            if(l > r) swap(l,r);
            if(l == 1 && r == n) {
                ans[i] = 3;
                continue;
            }
            if(l == 1) {
                ans[i] = 1;
            }
            else ans[i] = 2;
        }
        edge[l].pb({r,i});
        edge[r].pb({l,i});
    }
    if(m == n * (n - 1) / 2) {
        cout << 3 << '\n';
        for(int i = 1; i <= m; i ++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int root = -1; 
    for(int i = 1; i <= n; i ++) {
        if(edge[i].size() < n - 1) {
            root = i;
            break;
        }
    }
    debug(root);
    for(int i = 1; i <= m; i ++) ans[i] = 2;
    for(auto x: edge[root]) {
        ans[x.ss] = 1;
    }
    cout << 2 << '\n';
    for(int i = 1; i <= m; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    IOS
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}