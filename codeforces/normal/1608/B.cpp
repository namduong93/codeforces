/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include<bits/stdc++.h>
using namespace std;
 
//#define int long long
#define fto(i,a,b) for(int i=a;i<=b;++i)
#define fdo(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())
 
typedef pair<int, int> pii;
typedef long long ll;
 
const int mod=998244353;
const int N=200005;
const int inf =1e9+7;
 
int n,p[N];
string st;
int a,b;
void Solve() {
    cin>>n>>a>>b;
    if(abs(a-b)>1||a+b>n-2) {cout<<-1<<'\n';return ;}
    p[1]=0;
    int sm=0;
    int bg=0;
    int stop=-1;
    char pre='a';
    if(a>b) pre='b';
    if(a==b&&b==0) {fto(i,1,n) cout<<i<<' ';cout<<'\n';return;}
    fto(i,2,n) {
        if(a==0&&b==0) {
            stop=i;
            if(pre=='a') {
                sm--;
                p[i]=sm;
            }
            else {
                bg++;
                p[i]=bg;
            }
            break;
        }
        if(pre=='b') {
            bg++;
            p[i]=bg;
            a--;
            pre='a';
        }
        else {
            pre='b';
            sm--;
            p[i]=sm;
            b--;
        }
    }
    if(a!=0&&b!=0) {cout<<-1<<'\n';return ;}
    int Min=n+1;
    fto(i,1,stop) Min=min(Min,p[i]);
    fto(i,1,stop) p[i]=p[i]+abs(Min)+1;
    sm=sm+abs(Min)+1;
    bg=bg+abs(Min)+1;
    if(p[1]<p[2]) {
        fto(j,1,sm-1) cout<<j<<' ';
        cout<<p[1]<<' ';
        cout<<p[2]<<' ';
        fto(j,bg+1,n) cout<<j<<' ';
        fto(i,3,stop) cout<<p[i]<<' ';
        cout<<'\n';
    }
    if(p[1]>p[2]) {
        fdo(j,n,bg+1) cout<<j<<' ';
        cout<<p[1]<<' ';
        cout<<p[2]<<' ';
        fdo(j,sm-1,1) cout<<j<<' ';
        fto(i,3,stop) cout<<p[i]<<' ';
        cout<<'\n';
    }
}
int32_t main() {
  if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
 
  int Test;
  cin>>Test;
  fto(iTest,1,Test) {
    Solve();
  }
 
  return 0;
}