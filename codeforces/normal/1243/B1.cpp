#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int k,n;
string s,t;
vector<int> diff;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>k;
    fto(iTest,1,k)
    {
        cin>>n;
        cin>>s>>t;
        if(diff.size())
        diff.clear();
        fto(i,0,n-1)
        if(s[i]!=t[i])
        {
            diff.push_back(i);
        }
        if(diff.size()!=2) {cout<<"NO"<<'\n';continue;}
        if(s[diff[0]]==s[diff[1]]&&t[diff[0]]==t[diff[1]]) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}