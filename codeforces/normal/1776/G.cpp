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
const int N = 2000005;
const int inf = 1e9 + 7;

int n;
int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
multiset<int> ms;
int Count[N];
int countR[N];
int countResult[N];
void Solve()
{
    cin >> n;
    cin >> st;
    st = " " + st;
    fto(i,1,n * 2 - 1) {
        if(st[i] == 'W') {
            Count[i] = Count[i - 1] + 1;
        }
        else Count[i] = Count[i-1];
    }
    int rs = 0;
    fto(i, 1, n * 2 - 1) {
        if(i + n - 1 > n * 2 - 1) break;
        else {
            rs = max(rs, Count[i + n - 1] - Count[i - 1]);
        }
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
    //cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}