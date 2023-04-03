#include<bits/stdc++.h>
using namespace std;

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
int Test,n;
int a[205];
int main()
{
  //freopen("test.inp","r",stdin);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>n;
    int le,chan;
    le=0;chan=0;
    fto(i,1,n*2) {cin>>a[i];if(a[i]%2==1) le++;else chan++;}
    if(le!=chan) cout<<"No"<<'\n';else cout<<"Yes"<<'\n';
  }
}