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
deque<int> deq;
void Solve()
{
    int d;
    int cnt = 0;
    cin >> n >> d;
    fto(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    fto(i, 1, n) deq.push_back(a[i]);
    while (1)
    {

        if (!deq.size())
            break;
        int cc = deq.back();
        deq.pop_back();
        if (cc > d)
        {
            cnt++;
            continue;
        }
        int tmp = d / cc;
        if (deq.size() >= tmp)
        {
            while (tmp--)
            {
                deq.pop_front();
            }
            cnt++;
        }
        else
            break;
    }
    cout << cnt;
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