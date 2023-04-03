#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100005;
int n;
int a[N];
int phukluk[N];
int d[N];
int main()
{
    cin>>n;
    fto(i,1,n)
    cin>>a[i];
    fto(i,1,n)
    {
        if(a[i]>=0)phukluk[i]=-a[i]-1;
        else phukluk[i]=a[i];
    }
    if (n%2==1)
    {
        int x,y;
        x=y=1e9;
        fto(i,1,n)
        {
            if (phukluk[i]<x)
            {
                x=phukluk[i];
                y=i;
            }
        }
        phukluk[y]=-x-1;
    }
    for (int i=1;i<=n;i++)
    cout<<phukluk[i]<<' ';
}