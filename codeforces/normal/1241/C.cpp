#include<bits/stdc++.h>
#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int N=200005;
int n,k,test;
int a[N],b[N];
pii v1,v2;
bool check(int xx)
{
    int c=v1.se*v2.se/(__gcd(v1.se,v2.se));
    int tmp=0;
    fto(i,1,xx)
    b[i]=a[n-i+1];
    fto(i,1,xx/c)
    tmp+=b[i]/100*(v1.fi+v2.fi);
    fto(i,xx/c+1,xx/v1.se)
    tmp+=b[i]/100*v1.fi;
    fto(i,xx/v1.se+1,xx/v1.se+xx/v2.se-xx/c)
    tmp+=b[i]/100*v2.fi;
    return (tmp>=k);
}
void chatnp()
{
    int dau=1;
    int cuoi=n;
    int rs=-1;
    while(dau<=cuoi)
    {
        int mid=(dau+cuoi)/2;
        if(check(mid))
        {
            rs=mid;
            cuoi=mid-1;
        }
        else dau=mid+1;
    }
    cout<<rs<<'\n';
}
main()
{
    //freopen("test.inp","r",stdin);
    cin>>test;
    fto(iTest,1,test)
    {
        cin>>n;
        fto(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        cin>>v1.fi>>v1.se;
        cin>>v2.fi>>v2.se;
        if(v1<v2) swap(v1,v2);
        cin>>k;
        chatnp();
    }
}