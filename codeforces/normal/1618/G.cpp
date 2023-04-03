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
const int N=400005;
const int inf =1e9+7;

int n,m,q;
int a[N],b[N];
pii query[N],vertex[N],edge[N];
string st;
int sum[N];
int dsu[N];
int rs,ans[N];
pii sub[N];
int cal(int i,int j) {
    return sum[i]-sum[j];
}
int root(int u) {
    if(dsu[u]<0) return u;
    return root(dsu[u]);
}
int Union(int u,int v) {
    u=root(u);
    v=root(v);
    if(u==v) return 0;
    if(dsu[u]>dsu[v]) swap(u,v);
    dsu[u]+=dsu[v];
    dsu[v]=u;
    rs-=cal(sub[u].fi,sub[u].fi-sub[u].se);
    rs-=cal(sub[v].fi,sub[v].fi-sub[v].se);
    sub[u].fi=max(sub[u].fi,sub[v].fi);
    sub[u].se+=sub[v].se;
    //cout<<v;
    rs+=cal(sub[u].fi,sub[u].fi-sub[u].se);
    return 1;
}
void Solve() {
    cin>>n>>m>>q;
    fto(i,1,n) {
        dsu[i]=-1;
        cin>>a[i];
        vertex[i]=mp(a[i],1ll);
        rs+=a[i];
    }
    fto(i,1,m) {
        dsu[i+n]=-1;
        cin>>b[i];
        vertex[i+n]=mp(b[i],0ll);
    }
    sort(vertex+1,vertex+1+n+m);
    fto(i,1,n+m-1) {
        if(i==1) sum[i]=vertex[i].fi;
        sub[i]=mp(i,vertex[i].se);
        if(i==n+m-1) sub[i+1]=mp(i+1,vertex[i+1].se);
        sum[i+1]=sum[i]+vertex[i+1].fi;
        edge[i]=mp(vertex[i+1].fi-vertex[i].fi,i);
    }
    sort(edge+1,edge+m+n);
    fto(i,1,q) {
        cin>>query[i].fi;
        query[i].se=i;
    }
    sort(query+1,query+1+q);
    int tmp=1;
    fto(i,1,q) {
        while(tmp<=n+m-1&&edge[tmp].fi<=query[i].fi) {
            Union(edge[tmp].se,edge[tmp].se+1);
            tmp++;
        }
        ans[query[i].se]=rs;
    }
    fto(i,1,q) {
        cout<<ans[i]<<'\n';
    }
    return ;
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