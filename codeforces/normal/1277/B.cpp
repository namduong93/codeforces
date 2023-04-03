#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=2e5+2;
int t;
int a[N];
set< int, greater<int> > Set;
int main()
{
   // freopen("test.inp","r",stdin);
    cin>>t;
    fto(iTest,1,t)
    {
        int n,kq;
        kq=0;
        cin>>n;
        fto(i,1,n) {cin>>a[i];Set.insert(a[i]);};
        while(!Set.empty())
        {
            auto it=Set.begin();
            int tt=(*it);
            Set.erase(it);
            if(tt&1) continue;
            tt=tt/2;
            kq++;
            Set.insert(tt);
        }
        cout<<kq<<'\n';
    }
}