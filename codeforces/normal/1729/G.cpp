/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include <bits/stdc++.h>
using namespace std;

//#define int long long
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

const int mod = 1e9 + 7;
const int N = 200005;
const int inf = 1e9 + 7;

int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
multiset<int> ms;

int n, m;
int f[505][505];
string st1, st2;
void check(int i, int j)
{
    f[i][j] = (f[i + 1][j] | f[i][j - 1]);
    if (j - i + 1 > m)
        return;

    f[i][j] = true;
    fto(k, 1, m) if (st2[k] != st1[i + k - 1])
    {
        f[i][j] = false;
        return;
    }
}
int dp[505], cnt[505];
void solve()
{
    int Min = n + 1, Count = 0;
    for (int i = n; i >= 0; i--)
    {
        if (!f[i + 1][n])
        {
            if (Min > dp[i])
                Min = dp[i], Count = 0;
            if (Min == dp[i])
                Count = (Count + cnt[i]) % mod;
        }
    }

    cout << Min << ' ' << Count << '\n';
}
void Solve()
{
    cin >> st1 >> st2;
    st1 = " " + st1;
    st2 = " " + st2;
    n = st1.size() - 1, m = st2.size() - 1;

    memset(f, 0, sizeof f);

    fdo(i, n, 1) fto(j, i + m - 1, n) check(i, j);

    fto(i, 1, n + 1) dp[i] = n + 5, cnt[i] = 0;
    cnt[0] = 1;
    fto(i, 1, n)
    {
        if (i >= m)
        {
            if (f[i - m + 1][i])
            {
                for (int j = i - m; j >= 0; j--)
                {
                    if (!f[j + 1][i - m])
                    {
                        if (dp[i] > dp[j] + 1)
                            dp[i] = dp[j] + 1, cnt[i] = 0;
                        if (dp[i] == dp[j] + 1)
                            cnt[i] = (cnt[i] + cnt[j]) % mod;
                    }
                }
            }
        }
    }

    solve();
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

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}