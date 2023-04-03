#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define pii pair<int,int>
#define fi first
#define se second
const int N=100005;

int Test,n;
pii a[N];

int main()
{
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(i,1,Test)
  {
    cin>>n;
    fto(i,1,n) {cin>>a[i].fi;a[i].se=i;}
    sort(a+1,a+1+n);
    int dem=0;
    fto(i,1,n)
    {
      fto(j,1,i-1)
      {
        if(a[i].fi*a[j].fi>2*n) break;
        if(a[i].fi*a[j].fi==a[i].se+a[j].se) dem++;
      }
    }
    cout<<dem<<'\n';
  }
}