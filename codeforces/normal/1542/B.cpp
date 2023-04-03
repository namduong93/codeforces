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
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=100000;
int Test;
int n,a,b;
int Pow(int a,int b)
{
  if(b==0) return 1;
  if(b==1) return a;
  int cc=Pow(a,b/2);
  if(b%2==1) return cc*cc*a;
  return cc*cc;
}
#undef int
int main()
{
  #define int long long
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>n>>a>>b;
    if(a==1) { n--;if(n%b==0)cout<<"Yes"<<'\n';else cout<<"No"<<'\n';continue;}
    int tt=n;
    int dem=0;
    while(tt!=0) {tt=tt/a;dem++;}
    bool Boo=false;
    fto(i,0,dem)
    {
      int cc=n-Pow(a,i);
      if(cc>=0&&cc%b==0) Boo=true;
    }
    if(Boo) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
  }
}