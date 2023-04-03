#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
int n,a[N],k;
int main()
{
    cin>>n;
    fto(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    k=1;
    fto(i,1,n)
    if(a[i]>=k)
    {
                //cout<<a[i]<<' '<<k<<'\n';
        k++;
    }
    cout<<k-1;
}