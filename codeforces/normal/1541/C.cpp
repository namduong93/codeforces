#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
#define int long long
const int N=100005;

int Test,n;
int a[N];
#undef int
int main()
{
  #define int long long
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>n;
    fto(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int kq=0ll;
    kq+=a[n];
    int ss=0ll;
    fto(i,2,n)
    {
      ss+=(i-1)*(a[i]-a[i-1]);
      kq-=ss;
    }
    cout<<kq<<'\n';
  }
}