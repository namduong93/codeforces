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
string st1,st2;
void Solve() {
    int rs=inf;
    int cnt1=0;
    int cnt2=0;
    int cc=0;
    cin>>n;
    cin>>st1>>st2;
    fto(i,0,st1.length()-1) {
        if(st1[i]!=st2[i]) {
            cnt1++;
            if(st1[i]=='1') cc++;
            else cc--;
        }
    }
    if(cc==0) rs=cnt1;
    cc=0;
    fto(i,0,st1.length()-1) {
        if(st1[i]==st2[i]&&st1[i]=='1') cc++;
        if(st1[i]==st2[i]&&st1[i]=='0') cc--;
        if(st1[i]==st2[i]) cnt2++;
    }
    if(cc==1) rs=min(rs,cnt2);
    if(rs==inf) rs=-1;
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