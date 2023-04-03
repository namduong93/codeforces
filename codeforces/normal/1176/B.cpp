#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int t,n,a[105],d[4];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        d[0]=d[1]=d[2]=0;
        fto(i,1,n)
        {
            cin>>a[i];
            a[i]=a[i]%3;
            d[a[i]]++;
        }
        if(d[1]<=d[2]) cout<<d[1]+d[0]+(d[2]-d[1])/3<<'\n';
        else
        cout<<d[2]+d[0]+(d[1]-d[2])/3<<'\n';
    }
}