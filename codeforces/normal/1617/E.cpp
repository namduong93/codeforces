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
unordered_map<int,vector<int> >a;
unordered_map<int,int> pos;
unordered_map<int,bool> vertex;
unordered_map<int,bool> vis;
string st;
int ans=-1;
pii rs;
pii dfs(int u) {
    if(vis[u]) return {-1e9,u};
    vis[u]=true;
    pii t1={-1e9,u};
    if(vertex[u]) t1={0,u};
    if(a[u].size()) {
        fto(i,0,a[u].size()-1) {
            pii cur=dfs(a[u][i]);
            if(cur.fi+t1.fi>ans) {
                ans=cur.fi+t1.fi;
                rs={cur.se,t1.se};
            }
            t1=max(t1,cur);
        }
    }
    return {t1.fi+1,t1.se};
}
void Solve() {
    cin>>n;
    fto(i,1,n) {
        int x;
        cin>>x;
        pos[x]=i;
        vertex[x]=true;
        while(x) {
            int k=0;
            while((1<<k)<x) {
                k++;
            }
            int u=(1<<k)-x;
            int v=x;
            assert(u<v);
            a[u].push_back(v);
            x=u;
        }
    }
    //cout<<a[14].size();
    dfs(0);
    cout<<pos[rs.fi]<<' '<<pos[rs.se]<<' '<<ans;
}
int32_t main() {
    if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int Test;
    Test=1;
    fto(iTest,1,Test) {
        Solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}