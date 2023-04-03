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
pii a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
multiset<int> ms;

int b[N];
vector<pii> rr(n);
void rrh() {
    fto(i,1,n) {
        rr.push_back(a[i]);
    }
    sort(rr.begin(), rr.end());
    rr.resize(unique(rr.begin(), rr.end()) - rr.begin());
    fto(i,1,n) {
        // cout<<rr[i - 1].fi <<' '<<rr[i - 1].se<<'\n';
        b[i] = lower_bound(rr.begin(), rr.end(), a[i]) - rr.begin() + 1;
    }
}
int Max[N * 4];
int get(int x, int l, int r, int d, int c) {
    if(d <= l && r <= c) {
        return Max[x];
    }
    if(c < l || r < d) {
        return 0;
    }
    return max(get(x * 2, l , (l + r) / 2, d, c), get(x * 2 + 1, (l + r) / 2 + 1, r, d, c));
}
void update(int x, int l, int r, int u, int val) {
    if(u == l && u == r) {
        Max[x] = val;
        return ;
    }
    if(u < l || r < u) {
        return ;
    }
    update(x * 2, l, (l + r) / 2, u, val);
    update(x * 2 + 1, (l + r) / 2 + 1, r, u, val);
    Max[x] = max(Max[x * 2], Max[x * 2 + 1]);
    return ;
}
int F[N];
void Solve()
{
    int rs = 0;
    cin >> n;
    fto(i,1,n) {
        cin >> a[i].fi >> a[i].se;
        // rs = max(rs, a[i].se);
    }
    rrh();
    fto(i,1,n) {
        F[i] = get(1, 1, n, 1, b[i] - 1) + a[i].se - a[i].fi + 1;
        update(1, 1, n, b[i], F[i]);
    }
    int maxLis = *max_element(F + 1, F + 1 + n);
    // int maxEle = 1e9 + 7;
    // vector<int> Boo(n + 1);
    // fdo(i,n,1) {
    //     if(F[i] == maxLis && b[i] < maxEle) {
    //         Boo[i] = true;
    //         maxLis -- ;
    //         maxEle = b[i];
    //     }
    // }
    // fto(i,1,n) {
    //     if(Boo[i]) {
    //         cout<<a[i].fi <<' '<<a[i].se<<'\n';
    //         rs += (a[i].se - a[i].fi + 1);
    //     }
    // }
    // fto(i,1,n)
    cout << maxLis << '\n';
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

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}