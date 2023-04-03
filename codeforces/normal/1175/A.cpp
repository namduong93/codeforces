#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int t;
int n,k,dem;
main()
{
    cin>>t;
    fto(i,1,t)
    {
        dem=0;
        cin>>n>>k;
        while(n>0)
        {
            dem+=n%k;
            dem++;
            n=n/k;
        }
        cout<<dem-1<<'\n';
    }
}