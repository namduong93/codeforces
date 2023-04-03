/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Codeforces: codeforces.com
**/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;

const int mod=998244353;
const int N=200005;
const int inf =1000000000;

int n,m,a[N];
string st;
int len;
void Input() {
  cin>>n>>m;
  cin>>st;
  len=st.length();
  st=' '+st;
}
int Min1,Min2,Max1,Max2;
void Solve() {
    int dir1,dir2;
    pii rs;
    rs.fi=rs.se=1;
    dir1=dir2=0;
    Min1=Max1=Min2=Max2=0;
    //cout<<len;
    fto(i,1,len) {
        rs.fi=abs(Min2)+1;
        rs.se=abs(Min1)+1;
        rs.se;
        if(st[i]=='L') dir1--;
        if(st[i]=='R') dir1++;
        if(st[i]=='U') dir2--;
        if(st[i]=='D') dir2++;
        Min1=min(Min1,dir1);
        Max1=max(Max1,dir1);
        Min2=min(Min2,dir2);
        Max2=max(Max2,dir2);
        //cout<<i;
       //cout<<abs(Min1)+Max1+1;
        if(abs(Min1)+Max1+1>m) break;
        
        if(abs(Min2)+Max2+1>n) break;
        if(i==len) {
            rs.fi=abs(Min2)+1;
            rs.se=abs(Min1)+1;
        }
    }
    cout<<rs.fi<<' '<<rs.se<<'\n';
}
int32_t main() {
  if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Input();
    Solve();
  }

  return 0;
}