#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=105;
const int oo=1e15;
int n,x[N];
int rs,kq=oo;
 main()
{
    cin>>n;
    fto(i,1,n) cin>>x[i];
    fto(tt,1,n)
    {
        int st=x[tt];
        rs=0;
        fto(i,1,n)
        {
            rs+=abs(st-x[i])%2;
        }
        kq=min(kq,rs);
    }
    cout<<kq;
}