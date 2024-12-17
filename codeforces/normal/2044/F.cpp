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

int n, m, q;
int a[N], b[N];
vector<int> prime[N * 2];
string str;
stack<int> st;
bool visited[N * 2];
bool result[N * 2];
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void sieve()
{
    for (int i = 1; i <= 200000; ++i)
        for (int j = i; j <= 200000; j += i)
        {
            prime[j + 200000].push_back(i);
            prime[j + 200000].push_back(-i);
            prime[-j + 200000].push_back(i);
            prime[-j + 200000].push_back(-i);
        }
}

void Solve()
{
    cin >> n >> m >> q;
    int sigma_a = 0;
    int sigma_b = 0;
    fto(i, 1, n)
    {
        cin >> a[i];
        sigma_a += a[i];
    }
    fto(i, 1, m)
    {
        cin >> b[i];
        sigma_b += b[i];
    }
    map<int, bool> cnt_a, cnt_b;
    fto(i, 1, n)
    {
        cnt_a[sigma_a - a[i]] = true;
    }
    fto(i, 1, m)
    {
        cnt_b[sigma_b - b[i]] = true;
    }
    fto(i, 1, q)
    {
        int x;
        cin >> x;
        if (visited[x + 200000])
        {
            cout << ((result[x + 200000] != true) ? "NO" : "YES") << '\n';
            continue;
        }
        bool check = false;
        if (prime[x + 200000].size())
            for (auto v : prime[x + 200000])
            {
                if (cnt_a[v] && cnt_b[x / v])
                {
                    cout << "YES" << '\n';
                    check = true;
                    visited[x + 200000] = true;
                    result[x + 200000] = true;
                    break;
                }
            }
        if (!check)
        {
            cout << "NO" << '\n';
            visited[x + 200000] = true;
            result[x + 200000] = false;
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

    sieve();
    int Test = 1;
    // cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}