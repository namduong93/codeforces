/*
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

int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
set<int> s;
multiset<int> ms;

vector<int> rs[35];
void Solve()
{
    cin>>st;
    int n=st.length()-1;

    fto(i,0,'z'-'a') rs[i].clear();

    fto(i,0,n) {
        rs[st[i]-'a'].push_back(i+1);
    }
    vector<int> kq;
    if(st[0]<=st[n]) {
        fto(i,st[0]-'a',st[n]-'a') {
            if(rs[i].size()) {
                fto(j,0,rs[i].size()-1) {
                    kq.push_back(rs[i][j]);
                }
            }
        }
        cout<<st[n]-st[0]<<' '<<kq.size()<<'\n';
        fto(i,0,kq.size()-1) cout<<kq[i]<<' ';
        cout<<"\n";        
    }
    else {
        fdo(i,st[0]-'a',st[n]-'a') {
            if(rs[i].size()) {
                fto(j,0,rs[i].size()-1) {
                    kq.push_back(rs[i][j]);
                }
            }
        }
        cout<<st[0]-st[n]<<' '<<kq.size()<<'\n';
        fto(i,0,kq.size()-1) cout<<kq[i]<<' ';
        cout<<"\n";        
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
    cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}