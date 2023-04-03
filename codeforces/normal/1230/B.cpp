#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,k;
int a[200005];
string st;
int main()
{
    cin>>n>>k;
    cin>>st;
    fto(i,1,n)
    {
        a[i]=st[i-1]-'0';
    }
    if(n==1&&k!=0) {cout<<0;return 0;}
    if(a[1]!=1&&k!=0) {k--;a[1]=1;}
    fto(i,2,n)
    {
        if(a[i]!=0&&k!=0) {k--;a[i]=0;}
    }
    fto(i,1,n) cout<<a[i];
}