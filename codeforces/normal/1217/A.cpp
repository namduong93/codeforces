#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T;
int main()
{
   // freopen("test.inp","r",stdin);
    cin>>T;
    fto(i,1,T)
    {
        int str,in,exp,gg;
        cin>>str>>in>>exp;
        str+=exp;
        if(str<=in) cout<<0<<'\n';
        else
        {
            gg=(str-in)/2;
            if((str-in)%2==0) gg--;
            cout<<min(exp+1,gg+1)<<'\n';
        }
    }
}