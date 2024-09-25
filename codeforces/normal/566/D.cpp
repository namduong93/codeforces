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
const int N = 200005;
const int inf = 1e9 + 7;

int n, q;
int a[N], dsu[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
set<int> s;

int root(int u) {
    while(dsu[u] > 0) u = dsu[u];
    return u;
}

void merge(int u, int v) {
    u = root(u);
    v = root(v);
    if(u == v) return ;
    if(dsu[u] > dsu[v]) swap(u,v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

void Solve()
{
    cin >> n >> q;
    fto(i, 1, n) {
        s.insert(i);
        dsu[i] = -1;
    }
    fto(i, 1, q) {
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1) {
            merge(x, y);
        }
        if(type == 3) {
            cout << ((root(x) == root(y)) ? "YES" : "NO") << '\n';
        }
        if(type == 2) {
            int run = *s.lower_bound(x);
            while(run < y) {
                merge(run, run + 1);
                s.erase(run);
                run = *s.lower_bound(x);
            }
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