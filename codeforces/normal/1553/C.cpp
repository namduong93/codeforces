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

int n;
string st;
void Input() {
  cin>>st;
  st=' '+st;
}
void Solve() {
  int Boo=10;
  n=st.length()-1;
  fto(i,1,n){
    int goal1,goal2;
    goal1=goal2=0;
    fto(j,1,i) {
      if(j%2==1) {
        if(st[j]=='1') goal1++;
        if(st[j]=='?') goal1++;
        //if(i==5) cout<<j<<' '<<goal1<<'\n';
      }
      else {
        if(st[j]=='1') goal2++;
      }
    }
    int rm=10-i;
    if(goal1-goal2>rm/2+rm%2) Boo=min(Boo,i);

    goal1=goal2=0;
    fto(j,1,i) {
      if(j%2==1) {
        if(st[j]=='1') goal1++;
      }
      else {
        if(st[j]=='1') goal2++;
        if(st[j]=='?') goal2++;
      }
    }
    rm=10-i;
    if(goal2-goal1>rm/2) Boo=min(Boo,i);
  }
  cout<<Boo<<'\n';
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