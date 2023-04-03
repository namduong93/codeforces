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
#define SZ(x) ((int)(x).size())

const int N=1010;
const int mod=998244353ll;
string s,t;
void Input() {
  cin>>s>>t;
}
int HashS[N],HashT[N],RHashS[N],Pow[N];
ll getHash(int i,int j, int Hash[]) {
  return (Hash[j]-Hash[i-1]*Pow[j-i+1]+mod*mod)%mod;
}
void Solve() {
  bool Boo=false;
  int n=s.length();
  int m=t.length();
  s=' '+s;
  t=' '+t;
  fto(i,0,1000) {HashS[i]=0;HashT[i]=0;RHashS[i]=0;Pow[i]=0;}
  fto(i,1,n) HashS[i]=(HashS[i-1]*31+s[i]-'a'+1)%mod;
  fto(i,1,m) HashT[i]=(HashT[i-1]*31+t[i]-'a'+1)%mod;
  reverse(s.begin(),s.end());
  s=' '+s;
  fto(i,1,n) RHashS[i]=(RHashS[i-1]*31+s[i]-'a'+1)%mod;
  Pow[0]=1;
  fto(i,1,1000) Pow[i]=(Pow[i-1]*31)%mod;
  fto(i,1,n) {
    fto(j,1,m) {
      if(i>=j&&getHash(i-j+1,i,HashS)==getHash(1,j,HashT)){
        int st=n-(i-1)+1;
        int fn=st+(m-j)-1;
        if(j==m) {Boo=true;continue;}
        //if(i==5&&j==3) cout<<m;
        if(st<=fn&&fn<=n&&fn>0&&j!=m&&getHash(st,fn,RHashS)==getHash(j+1,m,HashT))
         Boo=true;
      }
    }
  }
  if(Boo) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';
}
#undef int
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