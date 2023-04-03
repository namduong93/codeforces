#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100002;
int n,m,rs;
bool Tham[N];
vector<int> a[N];
set<int> remain;
void dfs(int u)
{
    Tham[u]=true;
    remain.erase(u);
    if(a[u].size())
    fto(i,0,a[u].size()-1)
    {
        while(1)
        {
            auto it=remain.upper_bound(a[u][i]);
            if(it==remain.end()||*it>=a[u][i+1]) break;
            dfs(*it);
        }
    }
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n>>m;
    fto(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    fto(i,1,n) {a[i].push_back(0);a[i].push_back(n+1);}
    fto(i,1,n) sort(a[i].begin(),a[i].end());

    fto(i,1,n)
    remain.insert(i);

    fto(i,1,n)
    if(!Tham[i])
    {
        dfs(i);
        //cout<<i;
        rs++;
    }
    cout<<rs-1;
}