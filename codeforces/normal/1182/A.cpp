#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,D[65];
main()
{
    cin>>n;
    D[2]=2;
    fto(i,4,n)
    D[i]=D[i-2]*2;
    cout<<D[n];
}