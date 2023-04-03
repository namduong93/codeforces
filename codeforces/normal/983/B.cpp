/// SancioPanza93
#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=5005;
int n,a[N],q;
int mx[N][N],f[N][N];
int main()
{
    //freopen("test.inp","r",stdin);
    cin>>n;
    fto(i,1,n) cin>>a[i];
    fto(i,1,n) f[i][i]=a[i];
    fdo(i,n,1)
    fto(j,i+1,n)
    {
        f[i][j]=f[i][j-1]^f[i+1][j];
    }
    fdo(i,n,1)
    fto(j,i+1,n)
    f[i][j]=max(f[i][j],max(f[i][j-1],f[i+1][j]));
    //cout<<(f[1+1][3]^f[1][3-1])<<' '<<f[1][3];
    cin>>q;
    fto(i,1,q)
    {
        int l,r;
        cin>>l>>r;
        if(l==r) cout<<a[l]<<'\n';
        else cout<<f[l][r]<<'\n';
    }
}