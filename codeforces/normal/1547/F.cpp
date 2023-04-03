#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int oo= 1e15;
const int N=2e5+5;
int tmp2,n,a[N],GCD[4 * N];
void Input()
{
    tmp2=0;
    cin >> n;
    fto(i,1,n)
    {
        cin>>a[i];
        if(i==1) tmp2=a[i];
        else tmp2=__gcd(tmp2,a[i]);
    }
    fto(i,1,4*n) GCD[i]=0;
}
void build(int x,int l,int r)
{
  if(l==r) {GCD[x]=a[l];return ;}
  build(x*2,l,(l+r)/2);
  build(x*2+1,(l+r)/2+1,r);
  GCD[x]=__gcd(GCD[x*2],GCD[x*2+1]);
}
int get(int x,int l,int r,int d,int c)
{
    if(c<l||r<d) return 0;
    if(d<=l&&r<=c) return GCD[x];
    return __gcd(get(x*2,l,(l+r)/2,d,c),get(x*2+1,(l+r)/2+1,r,d,c));
}
bool check(int xx)
{
    fto(i,1,n)
    {
        int tmp=0;
        if(i+xx<=n) tmp=get(1,1,n,i,i+xx);
        else tmp=__gcd(get(1,1,n,1,i+xx-n),get(1,1,n,i,n));
        if(tmp!= tmp2) return false;
    }
    return true;
}
void tim()
{
    build(1,1,n);
    int dd=0,cc=n-1,rs=0;
    while(dd<=cc)
    {
        int mid=(dd+cc)/2;
        if(check(mid))
        {
          rs=mid,cc=mid-1;
        }
        else dd=mid+1;
    }
    cout<<rs<<'\n';
}
#undef int
int main()
{
    //freopen("test.inp","r",stdin);
    int Test;
    cin>>Test;
    fto(iTest,1,Test)
    {
    	Input();
    	tim();
    }
}