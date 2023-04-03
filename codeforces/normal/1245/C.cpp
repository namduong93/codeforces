#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=100005;
const int base=1e9+7;
int n,kq=1;
int block[N];
string st;
main()
{
    //freopen("test.inp","r",stdin);
    cin>>st;
    n=st.length();
    st=' '+st;
    block[1]=1;
    block[2]=2;
    fto(i,3,n)
    block[i]=(block[i-1]+block[i-2])%base;
    fto(i,1,n)
    {
        if(st[i]=='m') kq=0;
        if(st[i]=='w') kq=0;
        if(st[i]=='n')
        {
            int dem=0;
            while(st[i]=='n')
            {
                i++;
                dem++;
            }
            if(dem!=1)
            kq=(kq*block[dem])%base;
            i--;
            continue;
        }
        if(st[i]=='u')
        {
            int dem=0;
            while(st[i]=='u')
            {
                i++;
                dem++;
            }
            if(dem!=1)
            kq=(kq*block[dem]%base);
            i--;
            continue;
        }
    }
    cout<<kq;
}