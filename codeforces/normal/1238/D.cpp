#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=300005;
int n;
int f[N];
string st;
main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    cin>>st;
    st=' '+st;
    fto(i,1,n) f[i]=f[i-1]+(st[i]=='A');
    int rs=n*(n-1)/2;
    fto(i,1,n)
    {
        if(i!=n&&st[i]!=st[i+1]) rs--;
        int dau=1;
        int cuoi=i-1;
        int pos=-1;
        while(dau<=cuoi)
        {
            int mid=(dau+cuoi)/2;
            if(f[i]-f[mid-1]==i-mid+1||f[i]-f[mid-1]==0)
            {
                pos=mid;
                cuoi=mid-1;
            }
            else dau=mid+1;
        }
        if(pos!=1&&pos!=-1)
        {
           // cout<<pos-1<<' '<<i;
            rs--;
        }
        dau=i+1;
        cuoi=n;
        pos=-1;
        while(dau<=cuoi)
        {
            int mid=(dau+cuoi)/2;
            if(f[mid]-f[i-1]==mid-i+1||f[mid]-f[i-1]==0)
            {
                pos=mid;
                dau=mid+1;
            }
            else cuoi=mid-1;
        }
        if(pos!=n&&pos!=-1)
        {
            rs--;
           // cout<<i<<' '<<pos+1;
        }
    }
    cout<<rs;
}