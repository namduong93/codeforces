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

const int mod = 13;
const int N = 200005;
const int inf = 1e16 + 7;

string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;
int a[505][40005];

int n, home, rabbit, T;
int cnt;
int d[505], p[505][805];
map<pair<int, int>, int> Map;
pii edge[40005];
int D[205][205];

void print_Array()
{
    fto(i, 1, T)
    {
        fto(j, 1, cnt) cout << a[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
int rs[40005];
int Pow(int aa, int bb)
{
    if (bb == 0)
        return 1;
    if (bb == 1)
        return aa % mod;
    int cc = pow(aa, bb / 2);
    cc = (cc * cc) % mod;
    if (bb & 1)
        return (cc * aa) % mod;
    else
        return cc % mod;
}
void change_Array()
{
    //T++;
    a[1][1] = 1;
    a[1][2] = 0;
    a[1][3] = 0;
    a[2][1] = 0;
    a[2][2] = 0;
    a[2][3] = 1;
    a[3][1] = 0;
    a[3][2] = 1;
    a[3][3] = 2;
    a[1][4] = 3;
    a[2][4] = 10;
    a[3][4] = 1;
}
void Gaussian()
{
    //change_Array();
    //print_Array();
    fto(i, 1, cnt) rs[i] = -1;
    int curr = 0;
    fto(i, 1, cnt - 1)
    {
        //cout << i;
        if (curr > T)
            break;
        curr++;
        int Max_pos = curr;
        fto(j, curr + 1, T)
        {
            if (abs(a[j][i]) > abs(a[Max_pos][i]))
                Max_pos = j;
        }
        if (a[Max_pos][i] == 0)
        {
            curr--;
            continue;
        }
        fto(j, 1, cnt) swap(a[curr][j], a[Max_pos][j]);
        fto(j, curr + 1, T)
        {
            if (a[j][i] == 0)
                continue;
            int lcm = (a[curr][i] * a[j][i]) / __gcd(a[curr][i], a[j][i]);
            int cc1 = lcm / a[j][i];
            int cc2 = lcm / a[curr][i];
            fto(k, i, cnt)
            {
                a[j][k] = cc1 * a[j][k] - cc2 * a[curr][k];
                a[j][k] = (a[j][k] + mod * mod) % mod;
            }
        }
        // print_Array();
    }
    //print_Array();
    fdo(i, cnt - 1, 1)
    {
        fto(j, i + 1, cnt - 1)
        {
            //assert(rs[j] != -1);
            a[i][cnt] = a[i][cnt] - rs[j] * a[i][j];
            a[i][cnt] = (a[i][cnt] + mod * mod) % mod;
        }
        rs[i] = (a[i][cnt] * Pow(a[i][i], mod - 2)) % mod;
    }
}
void Find()
{
    fto(i, 1, n) fto(j, 1, n) D[i][j] = inf;
    fto(i, 1, n) D[i][i] = 0;
    fto(i, 1, cnt - 1)
    {
        D[edge[i].fi][edge[i].se] = rs[i];
        D[edge[i].se][edge[i].fi] = rs[i];
    }
    fto(k, 1, n)
    {
        fto(i, 1, n)
            fto(j, 1, n)
        {
            D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
        }
    }
    cout << D[home][rabbit];
}
void Solve()
{
    cin >> n >> home >> rabbit >> T;
    fto(i, 1, T) // 500
    {
        cin >> d[i] >> p[i][0];
        fto(j, 1, p[i][0])
        {
            cin >> p[i][j];
        }
        fto(j, 2, p[i][0]) // 800
        {
            int uu = p[i][j - 1];
            int vv = p[i][j];
            if (!Map[{uu, vv}]) //condition
            {
                cnt++; // 200*200
                Map[{uu, vv}] = cnt;
                Map[{vv, uu}] = cnt;
                edge[cnt] = {uu, vv};
            }
            a[i][Map[{uu, vv}]]++;
            a[i][Map[{uu, vv}]] %= mod;
        }
    }
    cnt++;
    fto(i, 1, T) a[i][cnt] = d[i];
    Gaussian();
    Find();
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