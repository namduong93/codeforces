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

int n,tt;
string a,s;
void Solve() {
    cin>>a>>s;
    string b="";
    int cuoi=s.length()-1;
    fdo(i,a.length()-1,0) {
        if(cuoi<0) {cout<<-1<<'\n';return;}
        if(a[i]>s[cuoi]){
            if(cuoi==0) {cout<<-1<<'\n';return;}
            tt=(s[cuoi-1]-'0')*10+s[cuoi]-a[i];
            cuoi=cuoi-2;
        }
        else  {
            tt=s[cuoi]-a[i];
            cuoi=cuoi-1;
        }
        if(tt<0||tt>9) {cout<<-1<<'\n';return;}
        b=char(tt+'0')+b;
    }
    if(cuoi>=0) fdo(i,cuoi,0) b=s[i]+b;
    int cc=0;
    while(b[cc]=='0') {
        cc++;
    }
    if(cc>b.length()-1) {cout<<0<<'\n';return;}
    fto(i,cc,b.length()-1)
    cout<<b[i];
    cout<<'\n';
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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}