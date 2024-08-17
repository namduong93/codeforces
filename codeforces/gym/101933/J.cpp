/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    test: 0 0 0 0, 1 1 1 0
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

int n;
string str;
string s[N];
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void Solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
        cout << "0";
        return;
    }

    int x = ceil(sqrt(a * 2));
    int y = ceil(sqrt(d * 2));
    if (x * (x - 1) / 2 != a)
    {
        cout << "impossible";
        return;
    }
    if (y * (y - 1) / 2 != d)
    {
        cout << "impossible";
        return;
    }
    if (a == 0 && (b >= 1 || c >= 1))
    {
        x = 1;
    }

    if (d == 0 && (b >= 1 || c >= 1))
    {
        y = 1;
    }
    if (x * y != b + c)
    {
        cout << "impossible";
        return;
    }
    int cloneX = x;
    int cloneY = y;
    vector<int> v;
    fto(i, 1, cloneX + cloneY)
    {
        if (b >= y)
        {
            v.push_back(0);
            b -= y;
        }
        else
        {
            v.push_back(1);
            y--;
        }
    }
    if (b != 0)
    {
        cout << "impossible";
        return;
    }
    if (v.size())
        fto(i, 0, v.size() - 1)
        {
            cout << v[i];
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