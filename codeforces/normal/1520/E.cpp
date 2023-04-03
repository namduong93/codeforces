#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define int long long
#define fdo(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e6+5;
int Test;
int n;
string str;
int sum[N],l[N],r[N];
int cnt[N];
#undef int
int main()
{
    #define int long long
    //freopen("test.inp","r",stdin);
    cin>>Test;
    fto(i,1,Test)
    {
        cin>>n;
        cin>>str;
        str=' '+str;
        fto(i,1,n)
        {
            l[i]=l[i-1]+cnt[i-1];
            if(str[i]=='*') cnt[i]=cnt[i-1]+1;
            else cnt[i]=cnt[i-1];
        }
        fto(i,1,cnt[n]) sum[i]=sum[i-1]+i;
        fdo(i,n,1) r[i]=r[i+1]+cnt[n]-cnt[i];
        int kq=1e15;
        //if(n==3) cout<<r[3]<<cnt[3]-cnt[3]<<' ';
        fto(i,1,n)
        {
            int tmp=l[i]+r[i+1];
            if(cnt[i]) tmp-=sum[cnt[i]-1];
            if(cnt[n]-cnt[i]) tmp-=sum[cnt[n]-cnt[i]-1];
            kq=min(kq,tmp);
        }
        fto(i,1,n) {l[i]=0;r[i]=0;cnt[i]=0;sum[i]=0;}
        cout<<kq<<'\n';
    }
}