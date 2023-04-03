#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<int,int> pii;
const int N=3e5+7;
set<pii> S;
int n,m;
pii a[N];
int pos[N],k[N];
int Ans[N];
bool cmp(pii c1,pii c2)
{
    if(c1.fi==c2.fi) return c1.se>c2.se;
    else return c1.fi<c2.fi;
}
struct ndv
{
    int fii,see,pos;
    bool operator < (const ndv &tmp)
    {
        if(fii==tmp.fii) return see<tmp.see;
        return fii<tmp.fii;
    }
};
ndv gg[N];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) {cin>>a[i].fi;a[i].se=i;}
    sort(a+1,a+1+n,cmp);
    cin>>m;
    int l=n;
    fto(i,1,m)
    {
        cin>>gg[i].fii>>gg[i].see;
        gg[i].pos=i;
    }
    sort(gg+1,gg+1+m);
    fto(i,1,m)
    {
        k[i]=gg[i].fii;pos[i]=gg[i].see;
        int dist=k[i]-k[i-1];
        fto(i,1,dist)
        {
            S.insert({a[l].se,a[l].fi});
            l--;
        }
        auto it=S.begin();
        fto(run,1,pos[i]-1) it++;
        Ans[gg[i].pos]=(*it).se;
    }
    fto(i,1,m) cout<<Ans[i]<<'\n';
}