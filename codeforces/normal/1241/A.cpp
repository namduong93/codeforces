#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int test;
int main()
{
    cin>>test;
    fto(i,1,test)
    {
        int n;
        cin>>n;
        if(n==2) {cout<<2<<'\n';;continue;}
        cout<<n%2<<'\n';
    }
}