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

int n,a[N];
string st;
string x1,x2;
int p1,p2;
void Solve() {
    cin>>x1>>p1;
    cin>>x2>>p2;
    if(x1==x2){
        if(p1>p2) cout<<">"<<'\n';
        if(p1<p2) cout<<"<"<<'\n';
        if(p1==p2) cout<<"="<<'\n';
        return ;
    }
    if(x1.length()+p1>x2.length()+p2) {
        cout<<">"<<'\n';
        return ;
    }
    if(x1.length()+p1<x2.length()+p2) {
        cout<<"<"<<'\n';
        return ;
    }
    if(x1.length()+p1==x2.length()+p2) {
        if(x1.length()>x2.length()) {
            fto(i,0,min(x1.length()-1,x2.length()-1)){
                if(x1[i]<x2[i]) {
                    cout<<"<"<<'\n';
                    return ;
                }
                if(x1[i]>x2[i]) {
                    cout<<">"<<'\n';
                    return ;
                }
            }
            bool Boo=false;
            fto(i,x2.length(),x1.length()-1) {
                if(x1[i]!='0') Boo=true;
            }
            if(!Boo) {
                cout<<"="<<'\n';
                return ;
            }
            cout<<">"<<'\n';
            return ;
        }
        if(x1.length()<x2.length()) {
            fto(i,0,min(x1.length()-1,x2.length()-1)){
                if(x1[i]<x2[i]) {
                    cout<<"<"<<'\n';
                    return ;
                }
                if(x1[i]>x2[i]) {
                    cout<<">"<<'\n';
                    return ;
                }
            }
            bool Boo=false;
            fto(i,x1.length(),x2.length()-1) {
                if(x2[i]!='0') Boo=true;
            }
            if(!Boo) {
                cout<<"="<<'\n';
                return ;
            }
            cout<<"<"<<'\n';
            return ;
        }
        if(x1.length()==x2.length()) {
            fto(i,0,x1.length()-1) {
                if(x1[i]==x2[i]) continue;
                if(x1[i]>x2[i]) {
                    cout<<">"<<'\n';
                    return ;
                }
                if(x1[i]<x2[i]) {
                    cout<<"<"<<'\n';
                    return ;
                }
            }
            cout<<"="<<'\n';
        }
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