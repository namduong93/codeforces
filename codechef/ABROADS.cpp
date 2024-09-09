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
#define int long long

int get_bit(int x, int i) { return x & (1 << i); }
int turn_bit(int x, int i) { return x | (1 << i); }
int swap_bit(int x, int i) { return x ^ (1 << i); }

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 500005;
const int inf = 1e9 + 7;

int n, m, q;
int a[N];
bool build[N];
pii edge[N], dsu[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;
struct Query {
    char ch;
    int num, value = 0, saved_value = 0;
};
multiset<int> res;
Query query[N];

int Root(int u) {
    while(dsu[u].fi > 0) u = dsu[u].fi;
    return u;
}
void Union(int u, int v) {
    u = Root(u);
    v = Root(v);
    if(u == v) return ;
    if(dsu[u] > dsu[v]) swap(u,v);
    
    res.erase(dsu[v].se);
    res.erase(dsu[u].se);
    
    dsu[u].fi += dsu[v].fi;
    dsu[u].se += dsu[v].se;
    
    res.insert(dsu[u].se);
    dsu[v].fi = u;
}
void Solve()
{
    cin >> n >> m >> q;
    fto(i, 1, n) {
        cin >> a[i];
    }    
    fto(i, 1, m) {
        cin >> edge[i].fi >> edge[i].se; 
        build[i] = true;
    }
    fto(i, 1, q) {
        cin >> query[i].ch;
        if(query[i].ch == 'D') {
            cin >> query[i].num;
            build[query[i].num] = false;
        }
        else {
            cin >> query[i].num >> query[i].value;
            query[i].saved_value = a[query[i].num];
            a[query[i].num] = query[i].value;
        }
    }
    stack<int> ans;
    fto(i, 1, n) {
        res.insert(a[i]);
        dsu[i].fi = -1;
        dsu[i].se = a[i];
    }
    fto(i, 1, m) {
        if(build[i]) {
            Union(edge[i].fi, edge[i].se);
        }
    }
    fdo(i, q, 1) {
        ans.push(*res.rbegin());
        if(query[i].ch == 'D') {
            build[query[i].num] = true;
            Union(edge[query[i].num].fi, edge[query[i].num].se);
        }
        else {
            int u = Root(query[i].num);
            res.erase(dsu[u].se);
            dsu[u].se += query[i].saved_value - query[i].value;
            res.insert(dsu[u].se);
            a[query[i].num] = query[i].saved_value;
        }
    }
    while(!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
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