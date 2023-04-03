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

string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
vector<int> s;
multiset<int> ms;
int dp[N][2];
int total[N];
void Solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> frac1, frac2;
    fto(i, 1, trunc(sqrt(a)))
    {
        if (a % i == 0)
        {
            frac1.push_back(i);
            if (i * i != a)
                frac1.push_back(a / i);
        }
    }
    fto(i, 1, trunc(sqrt(b)))
    {
        if (b % i == 0)
        {
            frac2.push_back(i);
            if (i * i != b)
                frac2.push_back(b / i);
        }
    }
    int x1, x2;
    x1 = x2 = -1;
    //cout << frac1.size() << '\n';
    fto(i, 0, frac1.size() - 1)
    {
        fto(j, 0, frac2.size() - 1)
        {
            int cc1 = frac1[i];
            int cc2 = frac2[j];
            int tmp1 = cc1 * cc2;
            int tmp2 = a * b / tmp1;
            if (a / tmp1 < c / tmp1 && b / tmp2 < d / tmp2)
            {
                x1 = c / tmp1 * tmp1;
                x2 = d / tmp2 * tmp2;
            }
        }
    }
    cout << x1 << ' ' << x2 << '\n';
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