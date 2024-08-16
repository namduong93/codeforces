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

#define int long long

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
int a[N];
string str;
string s[N];
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void Solve()
{
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    bool is_pos = a[1] > 0 ? true : false;
    int number = -inf;
    int res = 0;
    fto(i, 1, n)
    {
        if (a[i] < 0 && is_pos)
        {
            // cout << number;
            res += number;
            is_pos = false;
            number = a[i];
            continue;
        }
        if (a[i] > 0 && !is_pos)
        {
            // cout << number;
            res += number;
            is_pos = true;
            number = a[i];
            continue;
        }
        number = max(number, a[i]);
    }
    res += number;
    cout << res << '\n';
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