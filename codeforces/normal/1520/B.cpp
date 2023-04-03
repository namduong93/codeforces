#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
int main()
{
    //freopen("test.inp","r",stdin);
    int Test;
    cin>>Test;
    while(Test--)
    {
        cin>>n;
        int m=n;
        int Min=10;
        int sl=0;
        while(n!=0)
        {
            sl++;
            Min=min(Min,n%10);
            n=n/10;
        }
        int Boo=false;
        fto(i,1,9)
        if(!Boo)
        {
            int cc=0;
            fto(j,1,sl)cc=cc*10+i;
            if(cc>m) {cout<<(sl-1)*9+i-1<<'\n';Boo=true;}
            if(i==9&&!Boo) cout<<(sl-1)*9+i<<'\n';
        }
    }
}