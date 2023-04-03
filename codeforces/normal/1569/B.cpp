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

const int N=55;
const int inf =1000000000;
int n,a[N];
string st;
void Input() {
  cin>>n;
  cin>>st;
  st=' '+st;
}
char ch[N][N];
bool Boo[N];
vector<int> s;
void Solve() {
  if(s.size())
  s.clear();
  fto(i,1,n) {
    Boo[i]=false;
    if(st[i]=='2') s.push_back(i);
  }
  if(s.size()<=2&&s.size()>0) {cout<<"NO"<<'\n';return ;}

  fto(i,1,n) fto(j,1,n) ch[i][j]='!';

  fto(i,1,n)
  fto(j,i,n) {
    if(i==j) {ch[i][j]='X';continue;}
    if(st[i]=='1') {
      if(st[j]=='1') {
        ch[i][j]='=';
        ch[j][i]='=';
      }
      else {
        ch[i][j]='=';
        ch[j][i]='=';
      }
    }
    else {
      if(st[j]=='1') {
        ch[i][j]='-';
        ch[j][i]='+';
      }
    }
  }
  if(s.size())
  fto(i,0,s.size()-1)
  {
    if(i!=s.size()-1) {
      ch[s[i]][s[i+1]]='+';
      ch[s[i+1]][s[i]]='-';
    }
    else {
      ch[s[i]][s[0]]='+';
      ch[s[0]][s[i]]='-';
    }
  }

  fto(i,1,n)
  fto(j,1,n) if(ch[i][j]=='!') {
    ch[i][j]='=';
  }
  cout<<"YES"<<'\n';
  fto(i,1,n) {
  //  assert(ch[i][j]=='!');
    fto(j,1,n) cout<<ch[i][j];
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