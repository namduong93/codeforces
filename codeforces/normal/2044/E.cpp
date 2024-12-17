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

int n;
int a[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void Solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int Pow = 1;
    int res = 0;
    while (Pow * l1 <= r2)
    {
        int Powl1 = Pow * l1;
        int Powr1 = Pow * r1;
        if (Powl1 > r2)
            break;
        if (Powr1 < l2 || r2 < Powl1)
        {
            Pow *= k;
            continue;
        }
        int new_r2 = r2 / Pow;
        int new_l2 = l2 / Pow + (l2 % Pow != 0);
        if (new_l2 > new_r2)
            res += 0;
        else
        {
            res += min(new_r2, r1) - max(new_l2, l1) + 1;
        }
        Pow *= k;
        if (Pow > 1e9)
            break;
    }
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