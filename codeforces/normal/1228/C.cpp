#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int mod=1000000007;
int x,n,kq=1;
int F[63];
bool nt[100005];
vector<int> s;
void sang()
{
    fto(i,2,100000)
    if(!nt[i])
    {
        int j=i*i;
        while(j<=100000)
        {
            nt[j]=true;
            j+=i;
        }
    }
}
int Pow(int aa,int bb)
{
    if(bb==0) return 1;
    if(bb==1) return aa;
    int cc=Pow(aa,bb/2);
    cc=(cc*cc)%mod;
    if(bb&1) return (cc*aa)%mod;
    return cc;
}
int cal(int xx)
{
    int gg=1;
    int stop=0;
    fto(i,1,60)
    {
        if(gg<=n/xx)
        {
            gg*=xx;
            stop=i;
        }
        else break;
    }
    F[stop+1]=0;
    int rs=1;
    fdo(i,stop,1)
    {
        F[i]=n/gg;
        int t1=F[i]-F[i+1];
        t1=Pow(gg%mod,t1);
        rs=rs*t1;
        rs%=mod;
        gg/=xx;
    }
    return rs;
}
void sol()
{
    sang();
    fto(i,2,trunc(sqrt(x)))
    if(!nt[i])
    {
        if(x%i==0)
        {
            s.push_back(i);
            while(x%i==0)
                x=x/i;
        }
    }
    if(x!=1) s.push_back(x);
    fto(i,0,s.size()-1)
    {
        kq=(kq*cal(s[i]))%mod;
    }
    cout<<kq;
}
main()
{
   // freopen("1228C.inp","r",stdin);
    //freopen("1228C.out","w",stdout);
    cin>>x>>n;
    sol();
}