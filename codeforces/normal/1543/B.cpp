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
int n;
int a[200005];
#undef int
int main()
{
  #define int long long
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>Test;
  fto(iTest,1,Test)
  {
    int rs=0;
    int sum=0;
    cin>>n;
    fto(i,1,n) {cin>>a[i];sum+=a[i];}
    int cc=sum/n;
    fto(i,1,n) a[i]=cc;
    fto(i,1,sum-cc*n)
    a[i]++;
    fto(i,1,n) rs+=abs(sum-a[i]*n);
    cout<<rs/2<<'\n';
  }
}