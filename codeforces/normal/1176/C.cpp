#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=500005;
int n,a[N];
multiset<int> Set;
multiset<int> ::iterator it;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n)
    {
        cin>>a[i];
        if(a[i]==4) a[i]=1;
        if(a[i]==8) a[i]=2;
        if(a[i]==15)a[i]=3;
        if(a[i]==16) a[i]=4;
        if(a[i]==23) a[i]=5;
        if(a[i]==42) a[i]=6;
    }
    int res=n;
    fto(i,1,n)
    {
        if(a[i]==1) Set.insert(a[i]);
        else
        {
            it=Set.find(a[i]-1);
            if(it!=Set.end())
            {
                Set.erase(it);
                if(a[i]==6) res-=6;
                else
                Set.insert(a[i]);
            }
        }
    }
    cout<<res;
}