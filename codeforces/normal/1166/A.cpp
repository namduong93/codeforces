#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=105;
int n;
string a[N];
int r1[35],r2[35];
int x1,x2;
int main()
{
    cin>>n;
    fto(i,1,n)
    {
        cin>>a[i];
        if(r1[a[i][0]-'a']>=r2[a[i][0]-'a'])
        r2[a[i][0]-'a']++;
        else r1[a[i][0]-'a']++;
    }
    fto(i,'a','z')
    x1+=r1[i-'a']*(r1[i-'a']-1)/2;
    fto(i,'a','z')
    x2+=r2[i-'a']*(r2[i-'a']-1)/2;
    cout<<x1+x2;
}