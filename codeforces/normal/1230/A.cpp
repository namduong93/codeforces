#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,a[5];
int main()
{
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    n=4;
    if((a[1]+a[2]+a[3]+a[4])%2==1) {cout<<"NO";return 0;}
    fto(i,1,n-1)
    fto(j,i+1,n)
    {
        if(a[i]+a[j]==(a[1]+a[2]+a[3]+a[4])/2)
        {
            cout<<"YES";
            return 0;
        }
    }
    fto(i,1,n)
    {
        if(a[i]==(a[1]+a[2]+a[3]+a[4])/2)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}