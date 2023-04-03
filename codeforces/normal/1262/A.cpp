#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+7;
int T;
int n;
pii a[N];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        cin>>n;
        int Max=1e9+7;
        fto(i,1,n)
        {
            cin>>a[i].fi>>a[i].se;
            Max=min(Max,a[i].se);
        }
        sort(a+1,a+1+n);
        if(n==1) {cout<<0<<'\n';continue;}
        if(a[n].fi<=Max) {cout<<0<<'\n';continue;}
        cout<<a[n].fi-Max<<'\n';
    }
}