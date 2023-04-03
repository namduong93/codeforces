/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdo(i, a, b) for (int i = a; i >= b; --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())

int getBit(int x, int i)
{
    return x & (1 << i);
}
int turnBit(int x, int i) { return x | (1 << i); }
int swapBit(int x, int i) { return x ^ (1 << i); }

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 100005;
const int inf = 1e9 + 7;

vector<int> a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;
int sum[4 * N];
int n;
int Rank[N], val[N];
bool Tham[N];
int rs[N];

void update(int x, int l, int r, int u, int val)
{
    if (u == l && u == r)
    {
        sum[x] += val;
        return;
    }
    if (r < u || u < l)
        return;
    update(x * 2, l, (l + r) / 2, u, val);
    update(x * 2 + 1, (l + r) / 2 + 1, r, u, val);
    sum[x] = sum[x * 2] + sum[x * 2 + 1];
}
int get(int x, int l, int r, int d, int c)
{
    if (r < d || c < l)
        return 0;
    if (d <= l && r <= c)
        return sum[x];
    return get(x * 2, l, (l + r) / 2, d, c) + get(x * 2 + 1, (l + r) / 2 + 1, r, d, c);
}
void dfs(int u)
{
    Tham[u] = true;
    int tmp = 0;
    if (Rank[u] != 1)
        tmp = get(1, 1, 100000, 1, Rank[u] - 1);
    if (a[u].size())
    {
        fto(i, 0, a[u].size() - 1)
        {
            int v = a[u][i];
            if (!Tham[v])
            {
                dfs(v);
            }
        }
    }
    if (Rank[u] != 1)
        rs[u] = get(1, 1, 100000, 1, Rank[u] - 1);
    rs[u] -= tmp;
    update(1, 1, 100000, Rank[u], val[u]);
}
void Solve()
{
    int Root;
    cin >> n;
    fto(i, 1, n)
    {
        int u, Rankk, value;
        cin >> u >> Rankk >> value;
        if (u != -1)
        {
            a[u].push_back(i);
        }
        else
            Root = i;
        val[i] = value;
        Rank[i] = Rankk;
    }
    dfs(Root);
    fto(i, 1, n) cout << rs[i] << '\n';
}

int32_t main()
{

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Test = 1;
    //cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}