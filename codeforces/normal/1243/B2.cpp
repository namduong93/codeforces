#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int k,n;
string s,t;
vector< pair<int,int> > diff;
void solve()
{
    if(diff.size())
    diff.clear();

    fto(i,0,n-1)
    if(s[i]!=t[i])
    {
        if(i==n-1) {cout<<"NO"<<'\n';return;}
        bool kt=false;
        fto(j,i+1,n-1)
        if(s[j]==s[i]) {swap(s[j],t[i]);diff.push_back({j,i});kt=true;break;}
        if(kt==true) continue;
        fto(j,i+1,n-1)
        if(t[j]==s[i])
        {
            diff.push_back({i+1,j});
            diff.push_back({i+1,i});
            swap(t[j],s[i+1]);
            swap(s[i+1],t[i]);
            kt=true;
            break;
        }
        if(kt==false) {cout<<"NO"<<'\n';return ;}
    }
    cout<<"YES"<<'\n';
    cout<<diff.size()<<'\n';
    fto(i,0,diff.size()-1)
    cout<<diff[i].fi+1<<' '<<diff[i].se+1<<'\n';
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>k;
    fto(iTest,1,k)
    {
        cin>>n;
        cin>>s>>t;
        solve();

    }
}