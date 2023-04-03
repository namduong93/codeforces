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
int a[N];
string st;
vector<int>rr;
void rrh() {
    sort(rr.begin(),rr.end());
    rr.resize(unique(rr.begin(),rr.end())-rr.begin());
    fto(i,1,n) a[i]=lower_bound(rr.begin(),rr.end(),a[i])-rr.begin()+1;
}
int cnt[N],pos[N],rs[N];
void Solve() {
    rr.clear();
    cin>>n;
    vector<int> s[n+1];
    fto(i,1,n) {cin>>a[i];rr.push_back(a[i]);cnt[i]=0;pos[i]=0;rs[i]=i;}
    rrh();
    fto(i,1,n) {
        cnt[a[i]]++;
    }
    fto(i,1,n) if(cnt[i]==1) {cout<<-1<<'\n';return;}
    fto(i,1,n) {
        if(pos[a[i]]==0) {pos[a[i]]=i;rs[i]=i;continue;}
        swap(rs[i],rs[pos[a[i]]]);
    }
    fto(i,1,n) cout<<rs[i]<<' ';
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