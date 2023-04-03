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

int n;
int a,b,c;
string st;
void Solve() {
    cin>>a>>b>>c;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if(a>b) swap(a,b);
    if(a==b+c) {
        cout<<"YES"<<'\n';
        return ;
    }
    if(b==a+c) {
        cout<<"YES"<<'\n';
        return ;
    }
    if(c==a+b) {
        cout<<"YES"<<'\n';
        return ;
    }
    if(a==b&&c%2==0) {
        cout<<"YES"<<'\n';
        return ;
    }
    if(b==c&&a%2==0) {
        cout<<"YES"<<'\n';
        return ;
    }
    cout<<"NO"<<'\n';
    return ;
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