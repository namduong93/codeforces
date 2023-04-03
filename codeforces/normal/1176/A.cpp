#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int q;
const int dx[3]={2,3,5};
const int dy[3]={1,2,4};
main()
{
    //freopen("test.inp","r",stdin);
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int dem=0;
        bool Boo;
        while(n!=1)
        {
            Boo=false;
            fto(t,0,2)
            if(n%dx[t]==0)
            {
                n=n/dx[t];
                n=n*dy[t];
                dem++;
                Boo=true;
                break;
            }
            if(!Boo) {cout<<-1<<'\n';break;}
        }
        if(n==1) cout<<dem<<'\n';
    }
}