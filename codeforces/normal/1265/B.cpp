#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200005;
int t,a[N];
int n,d[N];
int Ans[N];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>t;
    fto(iTest,1,t)
    {
        int st;
        cin>>n;
        fto(i,1,n)
        {
            cin>>a[i];
            if(a[i]==1) st=i;
            d[a[i]]=i;
        }
        int l,r;
        l=r=st;
        Ans[1]=1;
        fto(i,2,n)
        {
            if(d[i]<l) l=d[i];
            if(d[i]>r) r=d[i];
            if(r-l+1==i) Ans[i]=1;
            else Ans[i]=0;
        }
        fto(i,1,n) cout<<Ans[i];
        cout<<'\n';
    }
}