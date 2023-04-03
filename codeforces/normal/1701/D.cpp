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
const int N=500005;
const int inf =1e9+7;

int n;
int a[N],rs[N];
string st;
struct seg {
    int fi,se,pos;
};
seg edge[N];
bool cmp(seg A,seg B){
    if(A.fi<B.fi) return true;
    if(A.fi==B.fi&&A.se<=B.se) return true;
    return false;
}
void Solve() {
    cin>>n;
    fto(i,1,n) cin>>a[i];
    fto(i,1,n) {
        if(a[i]==0) {edge[i].fi=min(n,i+1);edge[i].se=n;edge[i].pos=i;}
        else {
            edge[i].se=i/a[i];
            edge[i].fi=min(edge[i].se,i/(a[i]+1)+1);
            edge[i].pos=i;
        }
    }
    //fto(i,1,n) cout<<edge[i].fi<<' '<<edge[i].se;
    sort(edge+1,edge+1+n,cmp);
    set<pii> s;
    int j=1;
    fto(i,1,n) {
        while(edge[j].fi==i&&j<=n) {s.insert({edge[j].se,edge[j].pos});j++;}
        auto it=s.begin();
        a[it->second] = i;
        s.erase(it);
    }
    fto(i,1,n) cout<<a[i]<<' ';
    cout<<'\n';
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