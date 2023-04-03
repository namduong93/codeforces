/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
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
const int N = 200005;
const int inf = 1e9 + 7;

int n;
int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

int d[N];
bool Boo[N];

int dsu[N];
int root(int u) {
    while(dsu[u]>0) u=dsu[u];
    return u;
}
void Union(int u,int v) {
    u=root(u);
    v=root(v);
    if(u==v) return ;
    if(dsu[u]>dsu[v]) swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
}
map<int,int> mark;
void Solve()
{

    cin>>n;
    n*=2;
    cin>>st;
    st=' '+st;


    fto(i,1,n) Boo[i]=false;
    fto(i,1,n) dsu[i]=-1;

    int sum=0;

    mark.clear();

    fto(i,1,n) {
        if(st[i]=='(') sum+=1;
        else sum-=1;
        if(1==0) Union(i,1);
        else {
            if(sum==0) {
                mark.clear();
                Union(i,1);
                if(i!=n)
                Union(i+1,1);
            }
            if(mark[sum]&&st[i]==')')
            {
                Union(i,mark[sum]+1);
                if(i!=n&&st[i+1]=='(') Union(i,i+1);
            }
        }
        mark[sum]=i;
    }
    int cnt=0;
    fto(i,1,n) {
        int u=root(i);
        if(!Boo[u]) {cnt++;Boo[u]=true;}
    }
    cout<<cnt<<'\n';
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