#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=200000;
int n,a[N],tmp,dem;
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n)
    {
        cin>>a[i];
        if((a[i]+1164)%2==0) tmp+=a[i]/2;
        else
        {
            dem++;
            if(a[i]<0) tmp+=a[i]/2-1;
            else tmp+=a[i]/2;
        }
    }
    int need=dem+tmp;
    fto(i,1,n)
    {
        if((a[i]+1164)%2==0) cout<<a[i]/2<<'\n';
        else
        {
            if(a[i]<0)
            {
                if(need>0) cout<<a[i]/2<<'\n';
                else cout<<a[i]/2-1<<'\n';
            }
            else
            {
                if(need>0) cout<<a[i]/2+1<<'\n';
                else cout<<a[i]/2<<'\n';
            }
            need--;
        }
    }
}