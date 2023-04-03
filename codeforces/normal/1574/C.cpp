/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
**/
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
#define pii pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=200005;
const int inf =2000000000000000000;
int n,a[N];
string st;
int sum;
void Input() {
   cin>>n;
   sum=0;
   fto(i,1,n) {
      cin>>a[i];
      sum+=a[i];
   }
}
int bs1(int xx) { //first a[rs]>=xx
   int d=1;
   int c=n;
   int bsrs=-1;
   while(d<=c) {
      int mid=(d+c)/2;
      if(a[mid]>=xx) {
         bsrs=mid;
         c=mid-1;
      }
      else d=mid+1;
   }
   return bsrs;
}
int bs2(int xx) { //last a[rs]<=xx
   int d=1;
   int c=n;
   int bsrs=-1;
   while(d<=c) {
      int mid=(d+c)/2;
      if(a[mid]<=xx) {
         bsrs=mid;
         d=mid+1;
      }
      else c=mid-1;
   }
   return bsrs;
}
int m;
void Solve() {
   sort(a+1,a+1+n);
   cin>>m;
   fto(i,1,m) {
      int u,v,rs;
      rs=inf;
      cin>>u>>v;
      int tmp=bs1(u);
      if(tmp!=-1) {
         rs=min(rs,max(0ll,v-(sum-a[tmp])));
      }
          tmp=bs2(u);
      if(tmp!=-1) {
         rs=min(rs,u-a[tmp]+max(0ll,v-(sum-a[tmp])));
      }
      cout<<rs<<'\n';
   } 
}
int32_t main() {
  if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  Test=1; 
  //cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }

  return 0;
}