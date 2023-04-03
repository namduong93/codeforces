#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
main()
{
   // freopen("test.inp","r",stdin);
    int t;
    cin>>t;
    fto(iTest,1,t)
    {
        int n;
        cin>>n;
        int dem=0;
        fto(i,1,9)
        {
            int tmp=i;
            while(tmp<=n)
            {
                dem++;
                tmp=tmp*10+i;
            }
        }
        cout<<dem<<'\n';
    }
}