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

int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

void Solve()
{
    int rs = 0;
    int n;
    cin>>n;
    fto(i,1,n) cin>>a[i];
    bool stop=false;
    fto(i,2,n-1) {
        if(a[i]%2==0) rs+=a[i]/2;
        else {
            rs+=a[i]/2+1;
        }
        if(a[i]!=1) stop=true;
    }
    if(!stop&&n!=2) {cout<<-1<<'\n';return;} 
    if(n==3&&a[2]%2==1) {cout<<-1<<'\n';return;} 
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