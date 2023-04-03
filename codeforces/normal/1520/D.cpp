#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define int long long
using namespace std;
const int N=200005;
int Test,n;
int a[N];
int duong[N],am[N];
#undef int
int main()
{
#define int long long
   // freopen("test.inp","r",stdin);
    cin>>Test;
    while(Test--)
    {
        cin>>n;
        int kq=0;
        fto(i,0,n) {duong[i]=0;am[i]=0;}
        fto(i,1,n)
        {
            cin>>a[i];
            if(a[i]>=i) {kq+=duong[a[i]-i];duong[a[i]-i]++;}
            else {kq+=am[i-a[i]];am[i-a[i]]++;if(i==a[i]) kq+=duong[0];}
        }
        cout<<kq<<'\n';
    }
}