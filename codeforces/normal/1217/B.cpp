#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=105;
int t;
int n,x;
int Max,Max2;
int d[N],h[N];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>t;
    fto(tt,1,t)
    {
        bool kq=false;
        cin>>n>>x;
        Max=Max2=0;
        fto(i,1,n)
        {
            cin>>d[i]>>h[i];
            Max2=max(Max2,d[i]);
            if(d[i]>=x) kq=true;
        }
        if(kq) {cout<<1<<'\n';continue;}
        kq=false;
        fto(i,1,n)
        if(d[i]>h[i])
        {
            Max=max(Max,d[i]-h[i]);
            kq=true;
        }
        if(!kq) {cout<<-1<<'\n';continue;}
        int gg=ceil( (double)((x-Max2)/(double)Max ) );
        cout<<gg+1<<'\n';
    }
}