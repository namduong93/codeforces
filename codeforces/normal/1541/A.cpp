#include<bits/stdc++.h>
using namespace std;

#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
const int N=1000;

int Test,n;
int main()
{
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(i,1,Test)
  {
   cin>>n;
   if(n==2) {cout<<"2 1"<<'\n';continue;}
   if(n%2==0)
   {
     fto(i,1,n) if(i%2==0) cout<<i-1<<' '; else cout<<i+1<<' ';
     cout<<'\n';
   }
   else
   {
     cout<<3<<' '<<1<<' '<<2<<' ';
     fto(i,4,n) if(i%2==0) cout<<i+1<<' '; else cout<<i-1<<' ';
     cout<<'\n';
   }
  }
}