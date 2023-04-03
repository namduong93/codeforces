#include<bits/stdc++.h>
#define fi first
#define se second
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef pair<long long,long long> pii;
const int N=1000002;
int n,m;
pii h[N];
long long kq;
struct ndv
{
    int fii,see;
    long long val;
    bool operator < (const ndv &tmp) const
    {
        return see>tmp.see;
    }
};
ndv a[N];
double giaodiem(pii aa,pii bb)
{
    return (aa.se-bb.se)/(double)(bb.fi-aa.fi);
}
bool check(int id,int xx)
{
    if(id==m) return true;
    return xx<=giaodiem(h[id],h[id+1]);
}
long long get(int xx)
{
    int rs=-1;
    int dau=1;int cuoi=m;
    while(dau<=cuoi)
    {
        int mid=(dau+cuoi)/2;
        if(check(mid,xx)) {rs=mid;cuoi=mid-1;}
        else dau=mid+1;
    }
    if(rs==-1) rs=m;
    return h[rs].fi*xx+h[rs].se;
}
void add(pii aa)
{
    while(m>=2&&giaodiem(aa,h[m-1])<=giaodiem(h[m-1],h[m])) m--;
    h[++m]=aa;
}
void read(long long &v)
{
    char c;do{c=getchar();} while(!isdigit(c));
    v=c-'0';while(isdigit(c=getchar())) v=v*10+c-'0';
}
void read2(int &v)
{
    char c;do{c=getchar();} while(!isdigit(c));
    v=c-'0';while(isdigit(c=getchar())) v=v*10+c-'0';
}
void write(long long v)
{
    if(v<10) putchar(v+'0');
    else
    {
        write(v/10);
        putchar(v%10+'0');
    }
}
main()
{
   // freopen("test.inp","r",stdin);
    read2(n);
    fto(i,1,n)
    {read2(a[i].fii);read2(a[i].see);read(a[i].val);}

    sort(a+1,a+1+n);
    bool kt=false;
    add({0,0});
    fto(i,1,n)
    {
        long long cc=1LL*a[i].fii*a[i].see-a[i].val+get(-a[i].see);
        add({a[i].fii,cc});
        kq=max(kq,cc);
    }
    write(kq);
}