/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    comment: I dont understand why the TL of this problem is so fvckin tight
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
const int N = 100005;
const int inf = 1e9 + 7;

int n;
pii a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;
pii b[N];
int dau, cuoi;
int rs[35];
bool cmp(pii aa, pii bb)
{
    return (aa.se < bb.se);
}
void rrh(int tmp)
{
    vector<int> rr;
    rr.push_back(0);
    rr.push_back(tmp);
    fto(i, 1, n)
    {
        if (a[i].se >= tmp)
            break;
        rr.push_back(a[i].fi % tmp);
        rr.push_back((a[i].fi + a[i].se - 1) % tmp);
    }
    sort(rr.begin(), rr.end());
    rr.resize(unique(rr.begin(), rr.end()) - rr.begin());
    fto(i, 1, n)
    {
        if (a[i].se >= tmp)
            break;
        b[i].fi = lower_bound(rr.begin(), rr.end(), (a[i].fi) % tmp) - rr.begin() + 1;
        b[i].se = lower_bound(rr.begin(), rr.end(), (a[i].fi + a[i].se - 1) % tmp) - rr.begin() + 1;
    }
    dau = lower_bound(rr.begin(), rr.end(), 0) - rr.begin() + 1;
    cuoi = lower_bound(rr.begin(), rr.end(), tmp - 1) - rr.begin() + 1;
}
int tt[2 * N];
void Do2(int i)
{
    int tmp = 1 << i;
    int stop = n + 1;
    rrh(tmp);
    memset(tt, 0, sizeof(tt));
    fto(j, 1, n)
    {
        if (a[j].se >= tmp)
        {
            stop = j;
            break;
        }
        if (b[j].fi <= b[j].se)
        {
            tt[b[j].fi]++;
            tt[b[j].se + 1]--;
        }
        else
        {
            tt[b[j].fi]++;
            tt[cuoi + 1]--;
            tt[dau]++;
            tt[b[j].se + 1]--;
        }
    }
    fto(i, 1, min(n * 2, tmp))
        tt[i] += tt[i - 1];
    rs[i] = *max_element(tt + 1, tt + 1 + min(n * 2, tmp));
    rs[i] += n - stop + 1;
}
void Solve()
{
    scanf("%d", &n);
    fto(i, 1, n)
    {
        scanf("%d%d", &a[i].fi, &a[i].se);
        a[i].se = a[i].se - a[i].fi + 1;
    }
    sort(a + 1, a + 1 + n, cmp);
    int q;
    scanf("%d", &q);
    fto(i, 1, q)
    {
        int k, minMask;
        scanf("%d", &k);
        fto(mask, 0, 30)
        {
            if (getBit(k, mask))
            {
                minMask = mask;
                break;
            }
        }
        if (rs[minMask] == 0)
        {
            //Do(minMask);
            Do2(minMask);
        }
        printf("%d\n", rs[minMask]);
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
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}