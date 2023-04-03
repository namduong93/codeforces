#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=150005;
int n,a[N];
int T,rs,Min;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(tt,1,T)
    {
        rs=0;
        cin>>n;
        fto(i,1,n)
        cin>>a[i];
        Min=1e6+5;
        fdo(i,n,1)
        {
            if(a[i]>Min) rs++;
            Min=min(Min,a[i]);
        }
        cout<<rs<<'\n';
    }
}