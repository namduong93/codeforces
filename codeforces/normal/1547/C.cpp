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

const int N=1000;
int Test;
int k,n,m;
int a[N],b[N];
int rs[1000];
int main()
{
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>Test;
  fto(iTest,1,Test)
  {
    cin>>k>>n>>m;
    fto(i,1,n) cin>>a[i];
    fto(i,1,m) cin>>b[i];
    int pos1=1;
    int pos2=1;
    fto(i,k+1,k+n+m) rs[i]=-1;
    int debug=0;
    int kk=k+1;
    int dem=k;
    while(pos1<=n||pos2<=m)
    {
      if(a[pos1]==0&&pos1<=n) {dem++;pos1++;k++;rs[k]=0;continue;}
      if(b[pos2]==0&&pos2<=m) {dem++;pos2++;k++;rs[k]=0;continue;}
      if(a[pos1]<=dem&&pos1<=n)
      {
        k++;rs[k]=a[pos1];pos1++;continue;
      }
      if(b[pos2]<=dem&&pos2<=m)
      {
        k++;rs[k]=b[pos2];pos2++;continue;
      }
      {cout<<-1<<'\n';break;}
    }
    if(pos1==n+1&&pos2==m+1)
    {
      fto(i,kk,k) cout<<rs[i]<<' ';
      cout<<'\n';
    }
  }
}