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
string s1,s2;
void Input() {
  cin>>n;
  cin>>s1>>s2;
}
void Solve() {
  int rs=0;
  int tt=0;
  fto(i,0,s2.length()-1) {
    if(s2[i]=='0') continue;
    if(i!=0&&s1[i-1]=='1') {
      s1[i-1]='2';
      rs++;
      continue;
    }
    if(s1[i]=='0') {
      s1[i]='2';
      rs++;
      continue;
    }
    if(s1[i+1]=='1'&&i!=n-1) {
      s1[i+1]='2';
      rs++;
      continue;
    }
  }
  cout<<rs<<'\n';
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