#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int N=3000005;
int n,m;
vector<pii> s;
pii a[N];
int tmp1,tmp2,kq;
bool check(int u)
{
    tmp1=tmp2=kq=0;
    int si=s.size();
    fto(i,0,si-1)
    {
        if(s[i].fi!=u&&s[i].se!=u)
        {
            if(tmp1==0)
            {
                tmp1=s[i].fi;
                tmp2=s[i].se;
            }
            else
            {
                if(kq==0)
                {
                    if(s[i].fi!=tmp1&&s[i].fi!=tmp2&&s[i].se!=tmp1&&s[i].se!=tmp2) return false;
                    if(s[i].fi==tmp1) kq=1;
                    if(s[i].fi==tmp2) kq=2;
                    if(s[i].se==tmp1) kq=1;
                    if(s[i].se==tmp2) kq=2;
                }
                else
                {
                    if(kq==1&&s[i].fi!=tmp1&&s[i].se!=tmp1) return false;
                    if(kq==2&&s[i].fi!=tmp2&&s[i].se!=tmp2) return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin>>n>>m;
    fto(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        a[i].fi=min(u,v);
        a[i].se=max(u,v);
        s.push_back(a[i]);
    }
    sort(s.begin(),s.end());
    s.resize(unique(s.begin(),s.end())-s.begin());
    if(s.size()==1) {cout<<"YES";return 0;}
    else
    {
        if(check(s[0].fi)) {cout<<"YES";return 0;}
        if(check(s[0].se)) {cout<<"YES";return 0;}
    }
    cout<<"NO";
}