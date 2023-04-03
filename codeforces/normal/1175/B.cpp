//contest cacwj
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo=4294967296;
string st;
int x,t;
int sol(int p)
{
    int res=0;
    string str;
    int coppy;
    while (cin>>str)
    {
        if (res>=oo) return oo;
        if (str=="add")
        res+=p;
        if (str=="for")
        {
            cin>>coppy;
            res+=sol(coppy)*p;
        }
                if (res>=oo) return oo;
        if (str=="end")
        {
            return res;
        }
    }
}
main()
{
   // freopen("test.inp","r",stdin);
    cin>>t;
    int tmp=0;
    while (cin>>st)
    {
        if (st=="add") tmp++;
        if (st=="for")
        {
            int n;cin>>n;
            tmp+=sol(n);
        }
         if (tmp>=oo) { cout<<"OVERFLOW!!!"; return 0;}
                if(st=="end") {continue ; }
    }
    cout<<tmp;
    return 0;
}