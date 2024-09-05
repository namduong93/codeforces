/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 **/

// 4 2
// 2 5
// 1 8
// 9 10
// 8 11
#include <bits/stdc++.h>
using namespace std;

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

int n, k;
pii a[N];
string str;
stack<int> st;
priority_queue<int, vector<int>, greater<int>> d_heap;
multiset<int> ms;

bool cmp (const pii &f, const pii &s) {
    if(f.se != s.se) return f.se < s.se;
    return f.fi < s.fi;
}
void Solve()
{
    cin >> n >> k;
    fto(i,1,n) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n, cmp);
    int result = 0;
    fto(i,1,n) {
        if(ms.size() != 0) {
            auto it = ms.lower_bound(a[i].fi);
            if(it != ms.begin()) {
                it--;
                ms.erase(it);
                ms.insert(a[i].se);
                result++;
                continue;
            }
        }
        if(ms.size() < k) {
            ms.insert(a[i].se);
            result += 1;
        }
    }
    cout << result;
}

int32_t main()
{

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin);

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