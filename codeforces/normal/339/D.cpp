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
const int N = 200005;
const int inf = 1e9 + 7;

int n, m;
int a[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;
int bit[N * 4];

void build(int x, int l, int r, int depth) {
    if(l == r) {bit[x] = a[l];return;}
    build(x * 2, l, (l + r) / 2, depth + 1);
    build(x * 2 + 1, (l + r) / 2 + 1, r, depth + 1);
    if( (n - depth) & 1) {
        bit[x] = bit[x * 2] | bit[x * 2 + 1];
    }
    else {
        bit[x] = bit[x * 2] ^ bit[x * 2 +  1];
    }
    return ;
}
void update(int x, int l, int r, int u, int val, int depth) {
    if(u < l || u > r) {
        return ;
    }
    if(u == l && u == r) {
        bit[x] = val;
        return;
    }
    update(x * 2, l, (l+r) / 2, u, val, depth + 1);
    update(x * 2 + 1, (l+r) / 2 + 1, r, u, val, depth + 1);
    if( (n - depth) & 1) {
        bit[x] = bit[x * 2] | bit[x * 2 + 1];
    }
    else {
        bit[x] = bit[x * 2] ^ bit[x * 2 +  1];
    }
    return ;
}
void Solve()
{
    cin >> n >> m;
    fto(i, 1, 1 << n) {
        cin >> a[i];
    }
    build(1, 1, 1 << n, 0);
    fto(i, 1, m) {
        int p, b;
        cin >> p >> b;
        a[p] = b;
        update(1, 1, 1 << n, p, b, 0);
        cout << bit[1] << '\n';
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