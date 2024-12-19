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

int n;
int a[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void Solve()
{
    string s;
    cin >> s;
    s = ' ' + s;
    int start_0 = -1;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == '0')
        {
            start_0 = i;
            break;
        }
    }
    if (start_0 == -1)
    {
        cout << 1 << ' ' << 1 << ' ' << 1 << ' ' << s.length() - 1 << '\n';
        return;
    }
    int remain = s.length() - start_0;
    int Max = -2;
    int l1, r1;
    // cout << remain << ' ' << start_0 << '\n';
    for (int i = 1; i < s.length(); ++i)
    {
        int furthest = -1;
        if (i + remain - 1 >= s.length())
            break;
        for (int j = 0; j < remain; ++j)
        {
            if ((s[start_0 + j] - '0') ^ (s[i + j] - '0'))
                furthest = start_0 + j;
            else
            {
                break;
            }
        }
        if (Max < furthest)
        {
            Max = furthest;
            l1 = i;
            r1 = i + remain - 1;
        }
    }
    cout << l1 << ' ' << r1 << ' ' << 1 << ' ' << s.length() - 1 << '\n';
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