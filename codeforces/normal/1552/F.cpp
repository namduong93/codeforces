/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
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

int n;
struct Portal{
  int f,s,act;
} por[N];

int q[N],s[N];
void Input() {
  cin>>n;
  fto(i,1,n)
  cin>>por[i].s>>por[i].f>>por[i].act;
}
void Solve() {
  //cout<<"cc";
  fto(i,1,n) {
    //cout<<"cC";
    int rs=-1;
    int d=1;int c=i-1;
    while(d<=c) {
      int mid=(d+c)/2;
      if(por[mid].s>=por[i].f) {
        rs=mid;
        c=mid-1;
      }
      else d=mid+1;
    }
    //if(i==1) cout<<rs<<' ';
    q[i]=(por[i].s-por[i].f+mod)%mod;
    if(rs!=-1) q[i]=(q[i]+(s[i-1]-s[rs-1]+mod)%mod)%mod;
    s[i]=(s[i-1]+q[i])%mod;
  }
  int sum=1ll;
  fto(i,1,n) {
    if(por[i].act) sum=(sum+q[i])%mod;
  }
  sum=(sum+por[n].s)%mod;
  cout<<sum<<'\n';
}
#undef int
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  Test=1;
  //cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}