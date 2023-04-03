#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e5+7;
const int MOD=1000000007;
int n;
int Par[N];
int f[N][3];
vector<int> a[N];
void DFS(int u)
{
    if (u!=1) a[u].erase(find(begin(a[u]), end(a[u]), Par[u]));
    if(a[u].size())
    fto(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if(Par[u]!=v)
        {
            Par[v]=u;
            DFS(v);
        }
    }
    //------------------------------------
    vector<int> pre0(a[u].size(),1);
    vector<int> pre1(a[u].size(),1);
    vector<int> suf0(a[u].size()+1,1);
    vector<int> suf1(a[u].size()+1,1);
    int c1,c2,c3,c4;
    c1=c2=c3=c4=0;
    /*
    fto(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if(Par[v]==u)
    }*/
    //if (a[u].size() > 0) pre0[0] = f[a[u][0]][0];
    //if (a[u].size() > 0) pre1[0] = f[a[u][0]][1];

    if(a[u].size())
    fto(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if(Par[v]==u)
        {
            if(i==0)
            {
                pre0[0]=f[a[u][0]][0]%MOD;
                pre1[0]=f[a[u][0]][1]%MOD;
            }
            else
            {
                pre0[i]=(pre0[i-1]*f[v][0])%MOD;
                pre1[i]=(pre1[i-1]*f[v][1])%MOD;
            }
        }
    }
    if(a[u].size())
    fdo(i,a[u].size()-1,0)
    {
        int v=a[u][i];
        if(Par[v]==u)
        {
            suf0[i]=(suf0[i+1]*f[v][0])%MOD;
            suf1[i]=(suf1[i+1]*f[v][1])%MOD;
        }
    }
    //----------------------------------------
    c2 = pre1.size() ? pre1.back() : 1;
    if(a[u].size())
    fto(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if(Par[v]==u)
        {
            c1 = (c1 + f[v][2] * (i ? pre1[i - 1] : 1) % MOD * suf1[i + 1] % MOD) % MOD;
            c3 = (c3 + f[v][2] * (i ? pre0[i - 1] : 1) % MOD * suf0[i + 1] % MOD) % MOD;
        }
    }
    long long pre = 0;
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        c4 = (c4 + f[v][2] * suf0[i + 1] % MOD * pre % MOD) % MOD;
        pre = pre * f[v][0] % MOD;
        pre = (pre + f[v][2] * (i ? pre0[i - 1] : 1) % MOD) % MOD;
    }
    /*if(a[u].size())
    fto(i,0,a[u].size()-1)
    fto(j,i+1,a[u].size()-1)
    {
        int tmp=1;
        fto(kk,0,a[u].size()-1)
        if(kk!=i&&kk!=j)
        tmp=(tmp*f[a[u][kk]][0])%MOD;
        c4=(c4+(tmp*(f[a[u][i]][2]*f[a[u][j]][2])%MOD)%MOD)%MOD;
    }*/
    //------------------------------------------
    f[u][0] = (c1 + c4 + c2) % MOD;
    f[u][1] = c4;
    f[u][2] = (c2 + c3) % MOD;
   // if(u==4) cout<<c2;
    //----------------------------------------
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    DFS(1);
    cout<<f[1][0];
}