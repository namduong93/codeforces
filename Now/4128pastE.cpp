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

int n, m, k;
int a[N];
string st;
priority_queue<int, vector<int>, greater<int>> sHeap;
priority_queue<pii, vector<pii>, greater<pii>> pHeap;
multiset<int> ms;
int C;
vector<pii> pt;
map<int, int> ma, mi;
pii p[N];
bool cmp(pii A, pii B)
{
    if (A.first != B.first)
        return A.first > B.first;
    return A.second > B.second;
}
void Solve()
{
    cin >> n >> m >> k;
    fto(i, 1, n)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + n, cmp);
    int point = 0;
    fto(i, 1, k)
    {
        sHeap.push(p[i].second);
        point += min(m, p[i].second) * p[i].first;
    }
    cout << point;
    fto(i, k + 1, n)
    {
        if (sHeap.empty())
        {
            break;
        }
        if (sHeap.top() >= m)
        {
            break;
        }
        int tmp = sHeap.top();
        int finish = min(m, tmp + p[i].second);
        point += (finish - tmp) * p[i].first;
        sHeap.push(finish);
    }
    cout << point;
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

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}