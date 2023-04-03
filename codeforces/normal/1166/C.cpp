#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
int n,kq;
int a[N];
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) {cin>>a[i];a[i]=abs(a[i]);}
    sort(a+1,a+1+n);
    fto(i,1,n)
    {
        int d=1;int c=i-1;
        int res=-1;
        int mid;
        int x=a[i]/2;
        if(x*2<a[i]) x++;
        while(d<=c)
        {
            mid=(d+c)/2;
            if(a[mid]>=x)
            {
                res=mid;
                c=mid-1;
            }
            else d=mid+1;
        }
        if(res!=-1)
        kq+=i-res;
    }
    cout<<kq;
}