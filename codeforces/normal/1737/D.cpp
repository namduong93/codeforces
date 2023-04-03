/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    i miss Vn
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pair<int, int> >pipii;

const int mod = 998244353;
const int N = 200005;
const ll inf = 1e17 + 7;

vector<pii> a[N];
string st;
priority_queue<pipii, vector<pipii>, greater<pipii>> dHeap;
multiset<int> ms;
ll D[505][505];
ll mat[505][505];
int n,m;
vector<pipii> edge;

void Solve()
{
    cin>>n>>m;
    fto(i,0,n) {
        fto(j,0,n) {
            if(i!=j)
            mat[i][j] = inf;
            else mat[i][j]=0;
        }
    }
    edge.clear();
    fto(i,1,m) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        mat[u][v]=1;
        mat[v][u]=1;
        edge.push_back({w,{u,v}});
    }
    fto(i,1,n) mat[i][i]=0;
    fto(k,1,n) {
        fto(i,1,n) fto(j,1,n)
        mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
    }
    ll rs = inf;
    fto(i,0,edge.size()-1) {
        pipii x = edge[i];
        rs = min(rs,(mat[1][x.se.fi] + mat[x.se.se][n] + 1) * x.fi);
        rs = min(rs,(mat[1][x.se.se] + mat[x.se.fi][n] + 1) * x.fi);
        fto(xx,1,n)
        {
            rs = min(rs,(mat[1][xx] + mat[xx][n] + mat[xx][x.se.se] + 2) * x.fi);
            rs = min(rs,(mat[1][xx] + mat[xx][n] + mat[xx][x.se.fi] + 2) * x.fi);
        }
    }
    cout<<rs<<'\n';
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

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}