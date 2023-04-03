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
void Solve() { 
    cin>>n;
    fto(i,1,n) cin>>a[i];
    int t1=a[1];
    int t2=a[2];
    bool Boo1=false;
    bool Boo2=false;
    fto(i,1,n) {
        if(i%2==1) t1=__gcd(t1,a[i]);
        if(i%2==0) t2=__gcd(t2,a[i]);
    }
    fto(i,1,n) {
        if(i%2==0&&a[i]%t1==0) {
            Boo1=true;
        }
        if(i%2==1&&a[i]%t2==0) {
            Boo2=true;
        }
    }
    if(Boo1&&Boo2) {cout<<0<<'\n';return;}
    if(Boo1) {cout<<t2<<'\n';return;}
    if(Boo2) {cout<<t1<<'\n';return;}
    if(!Boo1&&!Boo2) {cout<<max(t1,t2)<<'\n';return ;}
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