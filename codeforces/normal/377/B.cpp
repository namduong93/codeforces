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

int n, m, s;
pii a[N];
pair<pii, int> b[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
int track[N], track_tmp[N];

bool check(int day) {
    int tmp_s = s;
    int student_iter = n;
    multiset<pii> ms;
    fdo(i, m, 1) {
        while(student_iter >= 0 && b[student_iter].fi.fi >= a[i].fi) {
            ms.insert({b[student_iter].fi.se, b[student_iter].se});
            student_iter--;
        }
        if(ms.empty()) {
            return false;
        }
        auto it = ms.begin();
        pii x = *it;
        ms.erase(it);
        fdo(j, i, max(i - day + 1, 1)) {
            track_tmp[a[j].se] = x.se;
        }
        i = max(i - day + 1, 1);
        tmp_s -= x.fi;
        if(tmp_s < 0) return false;
    }
    fto(i, 1, m) {
        track[i] = track_tmp[i];
    }
    return true;
}
void Solve()
{
    cin >> n >> m >> s;
    fto(i, 1, m) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + m);
    fto(i, 1, n) {
        cin >> b[i].fi.fi;
        b[i].se = i;
    }
    fto(i,1,n) {
        cin >> b[i].fi.se;
    }
    sort(b + 1, b + 1 + n);
    int l = 1, r = m;
    int rs = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(check(m)) {
            rs = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    if(rs == -1) {
        cout << "NO";
        return ;
    }
    cout << "YES" << '\n';
    fto(i, 1, m) {
        cout << track[i] <<' ';
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