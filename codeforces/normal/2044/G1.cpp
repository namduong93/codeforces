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
const int N = 300005;
const int inf = 1e9 + 7;

int n;
int r[N];
int Next[N], reverse_a[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;
bool visited[N];
int rs;
void dfs(int u)
{
    if (visited[Next[u]])
    {
        int v = Next[u];
        int cnt = 0;
        while (v != 0)
        {
            
            v = reverse_a[v];
            cnt++;
        }
        rs = max(rs, cnt);
    }
    else
    {
        visited[Next[u]] = true;
        dfs(Next[u]);
    }
}
void Solve()
{
    cin >> n;
    fto(i, 1, n)
    {
        cin >> r[i];
        Next[i] = r[i];
        reverse_a[r[i]] = i;
    }
    rs = 1;
    fto(i, 1, n)
    {
        if (reverse_a[i] == 0)
        {
            visited[i] = true;
            dfs(i);
        }
    }
    fto(i, 1, n)
    {
        Next[i] = 0;
        reverse_a[i] = 0;
    }
    cout << rs + 1 << '\n';
}

int32_t main()
{

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Test = 1;
    cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}