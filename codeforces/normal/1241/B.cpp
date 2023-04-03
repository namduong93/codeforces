#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int q;
string s,t;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>q;
    fto(iTest,1,q)
    {
        cin>>s>>t;
        bool kt=false;
        fto(i,0,s.length()-1)
        fto(j,0,t.length()-1)
        if(s[i]==t[j])
        kt=true;
        if(kt) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}