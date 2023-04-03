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

int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    vector<int> diff(n);
    for (int i = 0; i < n; i++)
        diff[i] = b[i] - a[i];

    vector<int> neg, pos;
    for (int i = 0; i < n; i++)
        if (diff[i] < 0)
            neg.push_back(diff[i]);
        else
            pos.push_back(diff[i]);

    sort(neg.begin(), neg.end(), greater<int>());
    sort(pos.begin(), pos.end(), greater<int>());

    int nNeg = 0;
    for (int low = 0, high = (int)min(neg.size(), pos.size()) - 1; low <= high;)
    {
        int mid = (low + high) >> 1;
        bool fail = false;
        for (int i = mid; i >= 0; i--)
        {
            if (abs(neg[i]) > pos[mid - i])
                fail = true;
        }
        if (!fail)
            nNeg = mid + 1, low = mid + 1;
        else
            high = mid - 1;
    }

    cout << nNeg + ((int)pos.size() - nNeg) / 2 << '\n';
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