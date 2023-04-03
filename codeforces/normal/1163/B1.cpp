#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,u[100005];
int D[15],res=1;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n)
    cin>>u[i];
    fto(i,1,n)
    {
        bool Boo;
        D[u[i]]++;
        fto(g,1,10)
        if(D[g]!=0)
        {
            Boo=true;
            int dem=0;
            dem=D[g]-1;
            fto(h,1,10)
            if(D[h]!=0)
            {
                if(g==h) continue;
                if(dem==0) dem=D[h];
                else if(dem!=D[h]) Boo=false;
            }
            if(Boo) break;
        }
        if(Boo)
        res=i;
    }
    cout<<res;
}