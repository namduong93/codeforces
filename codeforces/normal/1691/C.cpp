/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;
typedef long long ll;

const int mod=998244353;
const int N=200005;
const int inf =1e9+7;

int n,k;
int a[N];
string st;
void Solve() {
    cin>>n>>k;
    cin>>st;
    st=' '+st;
    int cc=-1;
    fto(i,1,n) {
        if(st[i]=='1') cc=i;
    }
    if(cc==-1) {cout<<0<<'\n';return;}
    if(n-cc<=k) {k-=(n-cc);swap(st[n],st[cc]);}
    cc=n+1;
    fdo(i,n-1,1) {
        if(st[i]=='1') cc=i;
    }
    if(cc!=n+1) {
        if(cc-1<=k) {k-=cc-1;swap(st[1],st[cc]);}
    }
    int rs=0;
    fto(i,2,n-1) {
        rs+=(st[i]-'0')*11;
    }
    rs+=(st[1]-'0')*10;
    if(n!=1) rs+=(st[n]-'0')*1;
    cout<<rs<<'\n';
}
int32_t main() {

    if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int Test;
    cin>>Test;
    fto(iTest,1,Test) {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}