/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 **/
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

int n, m;
int cnt[21][21];
int dp[(1 << 20)];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void Solve()
{
    cin >> n >> m;
    cin >> str;
    fto(i, 0, str.length() - 1) {
        if(i == 0) continue;
        int ch1 = str[i] - 'a';
        int ch2 = str[i - 1] - 'a';
        cnt[ch1][ch2] ++;
        cnt[ch2][ch1] ++;
    }
    fto(mask, 1, (1 << m) - 1) dp[mask] = inf;
    fto(mask, 0, (1 << m) - 1) {
        int tmp = 0;
        fto(j, 0, m - 1) if(get_bit(mask, j)){
            tmp++;
        }
        fto(j, 0, m - 1) if(!get_bit(mask, j)) {
            int total = 0;
            int new_mask = turn_bit(mask, j);
            fto(k, 0, m - 1)  {
                if(k == j) continue;
                if(get_bit(mask, k)) total += cnt[j][k] * tmp;
                else total -= cnt[j][k] * tmp;
            }
            dp[new_mask] = min(dp[new_mask], dp[mask] + total);
        }
    }
    cout << dp[(1 << m) - 1];
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

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}