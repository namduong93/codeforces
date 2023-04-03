#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
main()
{
    cin>>n;
    fto(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        if(abs(x-y)<=1) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}