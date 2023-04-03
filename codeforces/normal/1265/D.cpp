#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n;
int tt[100005];
int build(int a,int b,int c,int d)
{
     fto(i,2,n)
        {
            if(tt[i-1]==0)
            {
                if(b==0) {return 0;}
                tt[i]=1;b--;
            }
            if(tt[i-1]==1)
            {
                if(a!=0)
                {
                    tt[i]=0;
                    a--;
                }
                else
                {
                    if(c==0) {return 0;}
                    {tt[i]=2;c--;}
                }
            }
            if(tt[i-1]==2)
            {
                if(b!=0)
                {
                    tt[i]=1;
                    b--;
                }
                else
                {
                    if(d==0) {return 0;}
                    tt[i]=3;
                    d--;
                }
            }
            if(tt[i-1]==3)
            {
                if(c!=0)
                {
                    tt[i]=2;
                    c--;
                }
                else {return 0;}
            }
           // cout<<tt[i];
        }
        if(a!=0||b!=0||c!=0||d!=0){return 0;}
        cout<<"YES"<<'\n';
        fto(i,1,n) cout<<tt[i]<<' ';
        return 1;
}
int main()
{
   // freopen("test.inp","r",stdin);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    n=a+b+c+d;
    {
        tt[1]=0;
        if(build(a-1,b,c,d)==1) return 0;
        tt[1]=1;
        if(build(a,b-1,c,d)==1) return 0;
        tt[1]=2;
        if(build(a,b,c-1,d)==1) return 0;
        tt[1]=3;
        if(build(a,b,c,d-1)==1) return 0;
    }
    cout<<"NO";
}