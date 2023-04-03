#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int a[4];
int Test;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>Test;
    fto(iTest,1,Test)
    {
        cin>>a[1]>>a[2]>>a[3];
        sort(a+1,a+1+3);
        int kq=0;
        kq+=min(a[1],a[3]-a[2]);
        a[3]-=kq;
        a[1]-=kq;
        //cout<<a[1];
        if(a[1])
        {
            kq+=a[1]/2*2;
            a[3]-=a[1]/2;
            a[2]-=a[1]/2;
            a[1]=a[1]%2;
        }
        if(a[1]) {kq++;a[1]=0; a[3]-=1;}
        kq+=min(a[3],a[2]);
        cout<<kq<<'\n';
    }
}