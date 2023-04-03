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

int n;
int a[N];
string st;
bool compare(string aa, string bb) {
    fto(i,1,aa.length()-1) {
        if(aa[i]<bb[i]) return true;
        if(aa[i]>bb[i]) return false;
    }
    return true;
}
void Solve() {
    cin>>n;
    cin>>st;
    st=' '+st;
    fto(i,1,n-1) {
        if(st[i]<st[i+1]) {
            fto(j,1,i) cout<<st[j];
            fdo(j,i,1) cout<<st[j];
            cout<<'\n';
            return ;
        }
        if(st[i]==st[i+1]) {
            if(st[1]==st[i]) {
                fto(j,1,i) cout<<st[j];
                fdo(j,i,1) cout<<st[j];
                cout<<'\n';
                return ;
            }
        }
    }
    fto(i,1,n) cout<<st[i];
    fdo(i,n,1) cout<<st[i];
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