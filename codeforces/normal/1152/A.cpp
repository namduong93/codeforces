#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100005;
int n,m;
int a[N],Da[2],Db[2];
int b[N];
int main()
{
    cin>>n>>m;
    fto(i,1,n)
    {
        cin>>a[i];
        Da[a[i]%2]++;
    }
    fto(i,1,m)
    {
        cin>>b[i];
        Db[b[i]%2]++;
    }
    cout<<min(Db[1],Da[0])+min(Db[0],Da[1]);
}