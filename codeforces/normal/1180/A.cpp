#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
int rs=1;
main()
{
    cin>>n;
    fto(i,2,n)
    {
        rs+=(i-1)*4;
    }
    cout<<rs;
}