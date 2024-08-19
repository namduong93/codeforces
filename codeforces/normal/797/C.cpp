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
stack<char> st;
bool boo[N];
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
set<pair<char, int>> s;
multiset<int> ms;

void Solve()
{
    cin >> str;
    fto(i, 0, str.length() - 1)
    {
        s.insert({str[i], i});
    }
    int curr = 0;
    int iter = 0;
    while (!s.empty())
    {
        auto it = s.begin();
        pair<char, int> x = *it;
        if (st.empty())
        {
            cout << it->first;
            for (int j = curr; j <= x.second; ++j)
            {
                if (j != x.second)
                    st.push(str[j]);
                s.erase({str[j], j});
            }
            curr = x.second + 1;
        }
        else
        {
            if (it->first >= st.top())
            {
                cout << st.top();
                st.pop();
            }
            else
            {
                cout << it->first;
                for (int j = curr; j <= x.second; ++j)
                {
                    if (j != x.second)
                        st.push(str[j]);
                    s.erase({str[j], j});
                }
                curr = x.second + 1;
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
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
    // cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}