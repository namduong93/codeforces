#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e3+3;
const int base=1000000007;
int h,w,dem;
int r[N],c[N];
int a[N][N];
int Pow(int aa,int bb)
{
    if(bb==0) return 1;
    if(bb==1) return aa;
    int cc=Pow(aa,bb/2);
    cc=(cc*cc)%base;
    if(bb&1) return (cc*aa)%base;
    return cc;
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>h>>w;
    fto(i,1,h) fto(j,1,w) a[i][j]=-1;
    fto(i,1,h) cin>>r[i];
    fto(i,1,w) cin>>c[i];
    fto(i,1,h)
    {
        fto(j,1,r[i])
        {
            if(a[i][j]==0) {cout<<0;return 0;}
            a[i][j]=1;
        }
        if(a[i][r[i]+1]!=1)
        a[i][r[i]+1]=0;
        else {cout<<0;return 0;}
    }

    fto(i,1,w)
    {
        fto(j,1,c[i])
        {
            if(a[j][i]==0) {cout<<0;return 0;}
            a[j][i]=1;
        }
        if(a[c[i]+1][i]!=1)
        a[c[i]+1][i]=0;
        else {cout<<0;return 0;}
    }
    fto(i,1,h)
    fto(j,1,w)
    if(a[i][j]==-1) dem++;
    cout<<(Pow(2,dem)+base)%base;
}