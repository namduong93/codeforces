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

const int mod = 998244353;
const int N = 200005;
const int inf = 1e9 + 7;

int n;
int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    if (n % 2 == 1)
    {
        a = vector<int>(n - 1, 1);
        a.push_back(m - (n - 1));
    }
    else
    {
        if (m % 2 == 1)
            ;
        else
        {
            a = vector<int>(n - 2, 1);
            m -= n - 2;
            a.push_back(m / 2);
            a.push_back(m / 2);
        }
    }
    if (a.size() != n || *min_element(a.begin(), a.end()) < 1)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        for (int x : a)
            cout << x << ' ';
        cout << '\n';
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
    cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}