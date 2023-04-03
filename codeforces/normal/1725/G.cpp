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
const int N = 200005;
const int inf = 1e9 + 7;

int n;
int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

int cnt(int x)
{
    int cc1, cc2;
    if (x < 3)
        cc1 = 0;
    else
        cc1 = max(0ll, (x - 3) / 2 + 1);

    if (x < 8)
        cc2 = 0;
    else
        cc2 = max(0ll, (x - 8) / 4 + 1);
    return cc1 + cc2;
}
void Solve()
{
    cin >> n;
    int d = 1;
    int c = 2000000000;
    int rs = 0;
    while (d <= c)
    {
        int m = (d + c) / 2;
        if (cnt(m) >= n)
        {
            c = m - 1;
            rs = m;
        }
        else
            d = m + 1;
    }
    cout << rs;
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