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
bool Boo[3];
void Solve() {
    cin>>n;
    fto(i,0,2) Boo[i]=false;
    fto(i,1,n) {
        cin>>a[i];
        Boo[a[i]%3]=true;
    }
    sort(a+1,a+1+n);
    if(a[n]%3==0) {
        if(Boo[1]&&Boo[2]) {cout<<a[n]/3+1<<'\n';return;}
        if(!Boo[1]&&!Boo[2]) {cout<<a[n]/3<<'\n';return;}
        cout<<a[n]/3+1<<'\n';return;
    }
    if(a[n]%3==1) {
        if(Boo[2]) {
            if(a[1]==1) {cout<<a[n]/3+2<<'\n';return;}
            else {
                if(n==1) {cout<<a[n]/3+1<<'\n';return;}
                bool cc=false;
                fto(i,1,n) if(a[i]==a[n]-1) cc=true;
                if(cc) {cout<<a[n]/3+2<<'\n';return;}
                else {cout<<a[n]/3+1<<'\n';return;}
            }
        }
        else {
            cout<<a[n]/3+1<<'\n';
            return;
        }
    }
    if(a[n]%3==2) {
        if(Boo[1]) {cout<<a[n]/3+2<<'\n';return;}
        else {cout<<a[n]/3+1<<'\n';return;}
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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}