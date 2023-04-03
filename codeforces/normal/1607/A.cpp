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

int n,a[N];
string st,s;
void Input() {
    cin>>st;
    cin>>s;
}
void Solve() {
    int rs=0;
    int pos=-1;
    fto(i,0,s.length()) 
    {
        fto(j,0,st.length()-1) 
        {
            if(st[j]==s[i]) {
                if(pos!=-1) 
                rs+=abs(j-pos);
                pos=j;
            }
        }
    }
    cout<<rs<<'\n';
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