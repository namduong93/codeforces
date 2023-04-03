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
const int N=75;
const int inf =1e9+7;

int n;
double a[N];
string st;
double esp=1e-8;
void Solve() {
    cin>>n;
    int rs=n;
    fto(i,1,n) cin>>a[i];
    if(n<=2) {cout<<0<<'\n';return;}
    //if(n==6) cout<<rs;
    fto(i,1,n)
    fto(j,i+1,n) {
        int cc=0;
        double dis=(a[j]-a[i])/(j-i);
        double t1=a[i];
        fdo(t,i-1,1) {
            t1=t1-dis;
            if(abs(a[t]-t1)>esp) cc++;
        }
            t1=a[i];
        fto(t,i+1,n) {
            t1=t1+dis;
            //if(i==1&&j==4) cout<<a[t]-t1<<' ';
            if(abs(a[t]-t1)>esp) cc++;
        }
        rs=min(rs,cc);
    } 
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