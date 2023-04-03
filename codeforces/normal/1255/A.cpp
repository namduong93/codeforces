#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int T;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>T;
    fto(iTest,1,T)
    {
        int a,b;
        int kq=0;
        int rs=1e9;
        cin>>a>>b;
        if(a>b) swap(a,b);
        kq=0;
        int t1=(b-a)/5; kq+=t1; kq+=(b-t1*5-a)/2; kq+=(b-t1*5-a)%2;
        rs=min(rs,kq);
        kq=0;
        int t2=(b-a)/5+1; kq+=t2; kq+=(t2*5+a-b)/2; kq+=(t2*5+a-b)%2;
        rs=min(rs,kq);
        cout<<rs<<'\n';
    }
}