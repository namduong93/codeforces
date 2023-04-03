#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int mod=1e9+7;
const int N=100205;
int n;
int val[N],rs;
int Par[N];
vector<int> a[N];
map<int,int> st[N];
int gcd(int a,int b)
{
    if(a>b) swap(a,b);
    if(a&&b) return __gcd(a,b);
    return b;
}
void dfs(int u)
{
    if(u!=1)
    {
        int fa=Par[u];
        for(auto x:st[fa]) st[u][__gcd(x.fi,val[u])]+=x.se;
    }
    st[u][val[u]]++;
    for(auto x:st[u]) rs=(rs+x.fi*x.se)%mod;
    if(a[u].size())
    fto(i,0,a[u].size()-1) if(a[u][i]!=Par[u]){Par[a[u][i]]=u;dfs(a[u][i]);}
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) cin>>val[i];
    fto(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    cout<<rs;
}