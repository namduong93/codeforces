/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 **/
#include <bits/stdc++.h>
using namespace std;

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdo(i, a, b) for (int i = a; i >= b; --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())

int get_bit(int x, int i)
{
    return x & (1 << i);
}
int turn_bit(int x, int i) { return x | (1 << i); }
int swap_bit(int x, int i) { return x ^ (1 << i); }

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 500005;
const int inf = 1e9 + 7;

int n, q, cnt;
int pos[N], par[N];
pii seg[N];
bool visited[N];
vector<int> a[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;
int Min[4 * N], lazy[4 * N];

void dfs(int u) {
    cnt++;
    pos[u] = cnt;
    seg[u].fi = cnt;
    if(a[u].size()) {
        fto(i, 0, a[u].size() - 1) {
            int v = a[u][i];
            if(!visited[v]) {
                visited[v] = true;
                par[v] = pos[u];
                dfs(v);
            }
        }
    }
    seg[u].se = cnt;
}

void lazy_upd(int x, int l, int r) {
    if(lazy[x] != -1) {
        Min[x] = lazy[x];
    } else {
        return ;
    }
    if(l != r) {
        lazy[x * 2] = lazy[x];
        lazy[x * 2 + 1] = lazy[x];
    }
    lazy[x] = -1;
}

void update(int x, int l, int r, int d, int c, int val) {
    lazy_upd(x, l, r);
    if(c < l || r < d) return;
    if(d <= l && r <= c) {
        lazy[x] = val;
        lazy_upd(x, l, r);
        return ;
    }

    update(x * 2, l, (l + r) / 2, d, c, val);
    update(x * 2 + 1, (l + r) / 2 + 1, r, d, c, val);
    Min[x] = min(Min[x * 2], Min[x * 2 + 1]);
}

int get(int x, int l, int r, int d, int c) {
    lazy_upd(x, l, r);
    if(c < l || r < d) return 1;
    if(d <= l && r <= c) return Min[x];
    return min(get(x * 2, l, (l + r) / 2, d, c), get(x * 2 + 1, (l + r) / 2 + 1, r, d, c));
}

void Solve()
{
    cin >> n;
    fto(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    } 
    visited[1] =true;
    dfs(1);
    fto(i,1, 4*n) lazy[i] = -1;
    cin >> q;
    fto(i, 1, q) {
        int type, c;
        cin >> type >> c;
        if(type == 1) {
            // This will be a cool trick to counter test
            // 3
            // 1 3
            // 3 2
            // 4
            // 1 3
            // 2 2
            // 1 2
            // 3 3
            if (c > 1 && get(1, 1, n, seg[c].fi, seg[c].se) < 1) update(1, 1, n, par[c], par[c], 0);
	        update(1, 1, n, seg[c].fi, seg[c].se,1);
        }
        if(type == 2) {
            update(1, 1, n, pos[c], pos[c], 0);
        }
        if(type == 3) {
            cout << get(1, 1, n, seg[c].fi, seg[c].se) << '\n';
        }
    }
}

int32_t main()
{

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Test = 1;
    // cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}