#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T,a,b;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        cin>>a>>b;
        if(a==1||b==1) {cout<<"Finite"<<'\n';continue;}
        if(__gcd(a,b)!=1) cout<<"Infinite"<<'\n';
        else cout<<"Finite"<<'\n';
    }
}