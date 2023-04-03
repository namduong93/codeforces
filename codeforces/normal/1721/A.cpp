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

char ch[5];
void Solve()
{
    fto(i,1,4) cin>>ch[i];
    sort(ch+1,ch+1+4);
    if(ch[1]==ch[2]&&ch[2]==ch[3]&&ch[3]==ch[4]) {cout<<0<<'\n';return;}
    if(ch[1]==ch[2]&&ch[2]==ch[3]) {cout<<1<<'\n';return;}
    if(ch[2]==ch[3]&&ch[3]==ch[4]) {cout<<1<<'\n';return;}
    if(ch[1]==ch[2]&&ch[3]!=ch[4]) {cout<<2<<'\n';return;}
    if(ch[1]==ch[2]&&ch[3]==ch[4]) {cout<<1<<'\n';return;}
    if(ch[2]==ch[3]&&ch[1]!=ch[4]) {cout<<2<<'\n';return;}
    if(ch[3]==ch[4]&&ch[1]!=ch[2]) {cout<<2<<'\n';return;}
    {cout<<3<<'\n';return;}
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