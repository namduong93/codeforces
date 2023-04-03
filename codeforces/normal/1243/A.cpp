#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int k,n;
int a[2000];
int main()
{
  //  freopen("test.inp","r",stdin);
    cin>>k;
    fto(iTest,1,k)
    {
        int dem=0;
        int kq=0;
        cin>>n;
        fto(i,1,n) cin>>a[i];
        fto(i,1,n)
        {
            dem=0;
            fto(j,1,n)
            if(a[j]>=i) dem++;
            if(dem>=i) kq=i;
        }
        cout<<kq<<'\n';
    }
}