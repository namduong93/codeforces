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
#undef int
int main()
{
  #define int long long
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(iTest,1,Test)
  {
    int a,b;
    cin>>a>>b;
    if(a==b) {cout<<0<<' '<<0<<'\n';continue;}
    if(a<b) swap(a,b);
    int hieu=a-b;
    int t1=a/hieu;
    int t2=b/hieu;
    cout<<hieu<<' '<<min(abs(a-t1*hieu),abs(a-(t1+1)*hieu))<<'\n';
  }
}