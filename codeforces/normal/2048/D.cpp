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
const int N = 300005;
const int inf = 1e9 + 7;

int n, m;
int a[N], b[N], pre_b[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;
int cnt_tree[8 * N];

void update(int x, int l, int r, int u, int val)
{
    if (u < l || r < u)
        return;
    if (u == l && u == r)
    {
        cnt_tree[x] += val;
        return;
    }
    update(x * 2, l, (l + r) / 2, u, val);
    update(x * 2 + 1, (l + r) / 2 + 1, r, u, val);
    cnt_tree[x] = cnt_tree[x * 2] + cnt_tree[x * 2 + 1];
}
int get(int x, int l, int r, int d, int c)
{
    if (r < d || c < l)
        return 0;
    if (d <= l && r <= c)
        return cnt_tree[x];
    return get(x * 2, l, (l + r) / 2, d, c) + get(x * 2 + 1, (l + r) / 2 + 1, r, d, c);
}
void Solve()
{
    vector<int> rrh;
    cin >> n >> m;
    fto(i, 1, n)
    {
        cin >> a[i];
        rrh.push_back(a[i]);
    }
    fto(i, 1, m)
    {
        cin >> b[i];
        rrh.push_back(b[i]);
    }
    sort(b + 1, b + 1 + m);
    sort(rrh.begin(), rrh.end());
    rrh.resize(unique(rrh.begin(), rrh.end()) - rrh.begin());

    fto(i, 1, n) a[i] = lower_bound(rrh.begin(), rrh.end(), a[i]) - rrh.begin() + 1;
    fto(i, 1, m) b[i] = lower_bound(rrh.begin(), rrh.end(), b[i]) - rrh.begin() + 1;

    // fto(i, 1, n) cout << a[i] << ' ';
    // cout << '\n';
    // fto(i, 1, m) cout << b[i] << ' ';

    fto(i, 0, 4 * (n + m)) cnt_tree[i] = 0;
    fto(i, 1, n) update(1, 1, n + m, a[i], 1);
    fto(i, 1, m)
    {
        pre_b[i] = get(1, 1, n + m, b[i], n + m);
    }
    int cnt = 0;
    for (int k = 1; k <= m; ++k)
    {
        int start = 1;
        int end = start;
        int res = 0;
        bool pass = false;
        for (int j = 1; j <= m / k; ++j)
        {
            end = start + k - 1;
            if (b[end] <= a[1])
            {
                res += 1;
                start = end + 1;
            }
            else
            {
                if (pass)
                {
                    res += pre_b[start] + 1;
                    start = start - k;
                }
                else
                {
                    int d = start;
                    int c = end;
                    int tmp = c;
                    while (d <= c)
                    {
                        int m = (d + c) / 2;
                        if (b[m] > a[1])
                        {
                            tmp = m;
                            c = m - 1;
                        }
                        else
                            d = m + 1;
                    }
                    if (b[tmp] > a[1])
                    {
                        int remain = k - (tmp - start);
                        if (remain == 0)
                        {
                            res += 1;
                            start = m + 1;
                        }
                        else
                        {
                            res += pre_b[m - remain + 1] + 1;
                            start = m - remain + 1;
                        }
                    }
                    pass = true;
                    start = start - k;
                }
            }
        }
        cout << res << ' ';
    }
    cout << '\n';
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