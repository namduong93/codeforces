#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=35;
int n,m,r;
int s[N],b[N];
main()
{
    cin>>n>>m>>r;
    fto(i,1,n)
    cin>>s[i];
    fto(i,1,m) cin>>b[i];
    int mins=*min_element(s+1,s+1+n);
    int maxb=*max_element(b+1,b+1+m);
    cout<<max(r,r-(r/mins)*mins+(r/mins)*maxb);
}