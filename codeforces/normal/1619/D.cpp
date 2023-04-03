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
const int N=100005;
const int inf =1e9+7;

int n;
vector<int> a[N];
string st;
int m;
bool Boo[N];
bool check(int x) {
    fto(i,1,m) Boo[i]=false;
    bool dc=false;
    fto(i,1,n) {
        bool cc=false;
        fto(j,1,m) if(a[j][i]>=x) {
            if(Boo[j]) dc=true;
            Boo[j]=true;
            cc=true;
        }
        if(!cc) return false;
    }
    return dc;
}
void Solve() {
    cin>>m>>n;
    fto(i,1,m) a[i].resize(n+1);
    fto(i,1,m) fto(j,1,n) 
    {
        cin>>a[i][j];
    }
    int rs=0;
    int d=0; int c=1e9;
    while(d<=c) {
        int mid=(d+c)/2;
        if(check(mid)) {
            rs=mid;
            d=mid+1;
        }
        else c=mid-1;
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
        Solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}