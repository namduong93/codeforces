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
const int N = 300005;
const int inf = 1e9 + 7;

int n, m;
int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

map<int, bool> mark;
int d[N];
int Power(int aa, int bb)
{
    if (bb == 0)
        return 1;
    if (bb == 1)
        return aa % mod;
    int cc = Power(aa, bb / 2);
    cc = (cc * cc) % mod;
    if (bb & 1)
        return (cc * aa) % mod;
    return cc;
}
int sC[N], mC[N], gt[N];
void Solve()
{
    int sum = 0;
    int SDK = 0;
    cin >> n >> m;
    fto(i, 1, n)
    {
        mark[sum] = true;
        cin >> d[i];
        sum += d[i];
    }
    int tmp = 0;
    if (sum % 2 == 0)
    {
        fto(i, 1, n)
        {

            if (mark[tmp + sum / 2])
                SDK++;
            tmp += d[i];
        }
    }
    int cntAlone = n - SDK * 2;
    gt[0] = 1;
    fto(i, 1, n) gt[i] = (gt[i - 1] * i) % mod;
    mC[1] = m;
    fto(i, 2, m)
    {
        mC[i] = (mC[i - 1] * (m - i + 1)) % mod;
        mC[i] = (mC[i] * Power(i, mod - 2)) % mod;
    }
    sC[0] = mC[0] = 1;
    sC[1] = SDK;
    fto(i, 2, m)
    {
        sC[i] = (sC[i - 1] * (SDK - i + 1)) % mod;
        sC[i] = (sC[i] * Power(i, mod - 2)) % mod;
    }
    int rs = 0;
    fto(i, 0, min(m, SDK))
    {
        int tmp = (sC[i] * mC[i]) % mod;
        tmp = (tmp * gt[i]) % mod;
        tmp = (tmp * Power(m - i, cntAlone)) % mod;
        tmp = (tmp * Power(m - i, SDK - i)) % mod;
        tmp = (tmp * Power(m - i - 1, SDK - i)) % mod;
        rs = (rs + tmp) % mod;
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