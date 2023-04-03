#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int l,r;
bool Boo[11];
bool check(int xx)
{
    fto(i,0,9) Boo[i]=false;
    while(xx!=0)
    {
        if(Boo[xx%10]==true) return false;
        Boo[xx%10]=true;
        xx=xx/10;
    }
    return true;
}
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>l>>r;
    fto(i,l,r)
    {
        if(check(i)) {cout<<i;return 0;}
    }
    cout<<-1;
}