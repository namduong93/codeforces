/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
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
#define pii pair<int, int>
#define mod 998244353
#define SZ(x) ((int)(x).size())

const int N=100005;
const int inf =1000000000;
int n,a[N];
string st;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
}
void Solve() {
  int st=-1;
  fto(i,1,n) {if(a[i]==1) st=i;break;}

  if(*max_element(a+1,a+1+n)==0) {
    fto(i,1,n) cout<<i<<' ';
    cout<<n+1<<'\n';
    return ;
  }
  if(st==1) {
    cout<<n+1<<' ';
    fto(i,1,n) cout<<i<<' ';
    cout<<'\n';
    return ;
  }
  else {
    bool Boo=false;
    a[n+1]=-1;
    fto(i,1,n) {
      if(a[i]==0&&a[i+1]==1&&Boo==false) {
        cout<<i<<' '<<n+1<<' '<<i+1<<'\n';
        i++;
        Boo=true;
        continue;
      }
      cout<<i<<' ';
    }
    cout<<'\n';
  }
}
int main() {
  //freopen("test.inp","r",stdin);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }
}