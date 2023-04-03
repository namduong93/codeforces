/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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

int n,a[N];
string st;
int w,h,k;
void Solve() {
    cin>>w>>h;
    cin>>k;
    int rs=0;
    int Min,Max;
    int s1;
    Min=w+1;Max=-1;
    fto(i,1,k) {
        //int s1;
        cin>>s1;
        Min=min(Min,s1);
        Max=max(Max,s1);
    }
    rs=max(rs,(Max-Min)*h);

    cin>>k;
    Min=w+1;Max=-1;
    fto(i,1,k) {
        cin>>s1;
        Min=min(Min,s1);
        Max=max(Max,s1);
    }
    rs=max(rs,(Max-Min)*h);

    cin>>k;
    Min=h+1;Max=-1;
    fto(i,1,k) {
        cin>>s1;
        Min=min(Min,s1);
        Max=max(Max,s1);
    }
    rs=max(rs,(Max-Min)*w);

    cin>>k;
    Min=h+1;Max=-1;
    fto(i,1,k) {
        cin>>s1;
        Min=min(Min,s1);
        Max=max(Max,s1);
    }
    rs=max(rs,(Max-Min)*w);
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