#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,a[105];
int dem;
int main()
{
   // freopen("text.txt","r",stdin);
    cin>>n;
    fto(i,1,n)
    cin>>a[i];
    fto(i,1,n-1)
    {
        if(a[i]==2&&a[i+1]==3)
        {
            cout<<"Infinite";
            exit(0);
        }
        if(a[i]==3&&a[i+1]==2)
        {
            cout<<"Infinite";
            exit(0);
        }
    }
    fto(i,2,n)
    {
        if(a[i-1]==1)
        {
            if(a[i]==2&&a[i-2]==3) dem+=2;
            if(a[i]==3) dem+=4;
            if(a[i]==2&&a[i-2]!=3) dem+=3;
        }
        if(a[i-1]==2)
        if(a[i]==1) dem+=3;
        if(a[i-1]==3)
        if(a[i]==1) dem+=4;
    }
    cout<<"Finite"<<'\n';
    cout<<dem;
    exit(0);
}