#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int main()
{
   // freopen("test.inp","r",stdin);
    int Test;
    cin>>Test;
    fto(iTest,1,Test)
    {
        int a,b,c,r;
        cin>>a>>b>>c>>r;
        if(a>b) swap(a,b);
        if(c+r<a||c-r>b) {cout<<b-a<<'\n';continue;}
        int aa,bb;
        aa=max(a,c-r);
        bb=min(b,c+r);
        cout<<b-a-(bb-aa)<<'\n';
    }
}