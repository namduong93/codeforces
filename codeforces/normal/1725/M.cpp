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

typedef pair<int, pair<int, int>> pipii;
typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 200005;
const int inf = 1e16 + 7;

int n, m;
vector<pii> adj[N], radj[N];
string st;
priority_queue<pipii, vector<pipii>, greater<pipii>> dHeap;
set<int> s;
multiset<int> ms;

int d[N][2];

void dijsk()
{
    fto(i, 1, n) fto(j, 0, 1) d[i][j] = inf;
    d[1][0] = 0;
    d[1][1] = 0;
    dHeap.push({0, {1, 0}});
    dHeap.push({0, {1, 1}});
    while (!dHeap.empty())
    {
        pipii x = dHeap.top();
        dHeap.pop();
        if (d[x.se.fi][x.se.se] != x.fi)
            continue;
        if (1)
        {
            if (radj[x.se.fi].size())
            {
                fto(i, 0, radj[x.se.fi].size() - 1)
                {
                    pii v = radj[x.se.fi][i];
                    if (d[v.fi][1] > x.fi + v.se)
                    {
                        d[v.fi][1] = x.fi + v.se;
                        dHeap.push({d[v.fi][1], {v.fi, 1}});
                    }
                }
            }
        }
        if (x.se.se == 0)
        {
            if (adj[x.se.fi].size())
            {
                fto(i, 0, adj[x.se.fi].size() - 1)
                {
                    pii v = adj[x.se.fi][i];
                    if (d[v.fi][0] > x.fi + v.se)
                    {
                        d[v.fi][0] = x.fi + v.se;
                        dHeap.push({d[v.fi][0], {v.fi, 0}});
                    }
                }
            }
        }
    }
}
void Solve()
{
    cin >> n >> m;
    fto(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }
    dijsk();
    fto(i, 2, n)
    {
        if (d[i][0] == inf && d[i][1] == inf)
            cout << -1 << ' ';
        else
            cout << min(d[i][0], d[i][1]) << ' ';
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
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}