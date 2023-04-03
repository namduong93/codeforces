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

const int N=25;

bool Boo=false;

int n,a[N];
int x[N];
vector<int> s;
void Input() {
  cin>>n;
  fto(i,1,n) cin>>a[i];
}
int dem=0;
void update(int xx) {
    int sum=0;
    fto(i,0,n-2) {
      if(x[i]!=0) {
        if(x[i]==1) sum+=s[i];
        else sum-=s[i];
      }
    }
    if(sum==xx) Boo=true;
}
void Try(int i,int xx) {
  fto(j,0,2) {
    x[i]=j;
    if(i==n-2) update(xx);
    else Try(i+1,xx);
  }
}
void Solve() {

  fto(i,1,n) {
    if(a[i]==0) {
      cout<<"YES"<<'\n';
      return;
    }
  }

  if(n==1) {
    cout<<"NO"<<'\n';
    return ;
  }

  fto(i,1,n) {
    s.clear();
    fto(j,1,n) {
      if(i!=j) s.push_back(a[j]);
      //if(i==1) cout<<a[j];
    }
    //if(i==1) fto(i,0,s.size()-1) cout<<s[i]<<' ';
    Boo=false;
    Try(0,a[i]);
    if(Boo) {cout<<"YES"<<'\n';return ;}
  }
  cout<<"NO"<<'\n';
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