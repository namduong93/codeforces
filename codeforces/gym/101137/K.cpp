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
const int N=300005;
const int inf =1e9+7;

int n,m;
int a[N],b[N];
string st;

struct Edge{
    int u,v,w;
};
Edge edge[N];
int dsu[N];
int number[N],cost[N],sum[N];
bool cmp(Edge A, Edge B) {
    return A.w<B.w;
}
int root(int u) {
    while(dsu[u]>0) u=dsu[u];
    return u;
}
void Union(Edge E) {
    E.u=root(E.u);
    E.v=root(E.v);
    if(E.u==E.v) return ;
    if(dsu[E.u]>dsu[E.v]) swap(E.u,E.v);
    dsu[E.u]+=dsu[E.v];
    dsu[E.v]=E.u;
    number[E.u]=max(max(number[E.u],number[E.v]),E.w);
    cost[E.u]=min(cost[E.u],cost[E.v]);
    sum[E.u]=min(sum[E.u]+sum[E.v],number[E.u]*cost[E.u]);
}
void Solve() {
    cin>>n>>m;
    fto(i,1,n)  {
        cin>>a[i]>>b[i];
        dsu[i]=-1;
        cost[i]=b[i];
        number[i]=a[i];
        sum[i]=a[i]*b[i];
    }
    fto(i,1,m) {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge+1,edge+1+m,cmp);
    fto(i,1,m) {
        Union(edge[i]);
    }
    int rs=0;
    fto(i,1,n) if(dsu[i]<0){
        rs+=sum[i];
    }
    cout<<rs;
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