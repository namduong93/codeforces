#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int q,n,r;
int x[100005];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>q;
    fto(i,1,q)
    {
        cin>>n>>r;
        fto(i,1,n) cin>>x[i];
        sort(x+1,x+1+n);
        int stop=0;
        int dem=0;
        x[n+1]=0;
        fdo(i,n,1)
        if(x[i]!=x[i+1])
        {
            if(x[i]<=stop)
            break;
            dem++;
            stop+=r;
        }
        cout<<dem<<'\n';
    }
}