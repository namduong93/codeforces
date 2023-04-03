#include<bits/stdc++.h>
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
#define mod 1000000007
#define SZ(x) ((int)(x).size())

const int N=100000;
int Test;
int n;
#undef int
int main()
{
  #define int long long
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>n;
    if(n==1) {cout<<2<<'\n';continue;}
    int tt=1;
    int mso=1;
    int rs=0;
    int debug=0;
    int nn=n;
    while(n)
    {
      tt=(tt+1)%mod;
      mso=(mso*tt)/__gcd(mso,tt);
      rs=(rs+((n-nn/mso)%mod*tt)%mod)%mod;
      n=nn/mso;
    }
    cout<<rs<<'\n';
  }
}