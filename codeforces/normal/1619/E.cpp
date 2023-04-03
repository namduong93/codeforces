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
int f[N];
vector<int> v;
void Solve() {
    cin>>n;
    fto(i,0,n) f[i]=0;
    v.clear();
    fto(i,1,n) {cin>>a[i];f[a[i]]++;}
    int own=0;
    fto(i,0,n) {
        cout<<f[i]+own<<' ';
        fto(j,1,f[i]) v.push_back(i);
        if(v.empty()) {
            fto(j,i+1,n) cout<<-1<<' ';
            cout<<'\n';
            return ;
        }
        //if(i==0) cout<<v.back();
        own+=i-v.back();
        v.pop_back();
    }
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