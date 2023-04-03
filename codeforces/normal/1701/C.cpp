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

int n,m;
int worker[N];
int a[N];
string st;
bool check(int time) {
    int job=m;
    int can=0;
    fto(i,1,n) {
        int cc=min(worker[i],time);
        job-=cc;
        can+=(time-cc)/2;
        if(job<=0) return true;
        if(can>=job) return true;
    }
    if(can>=job) return true;
    return false;
}
void Solve() {
    cin>>n>>m;
    fto(i,1,n) worker[i]=0;
    fto(i,1,m) {cin>>a[i];worker[a[i]]++;}
    int d=0;
    int c=500000;
    int rs=-1;
    while(d<=c) {
        int m=(d+c)/2;
        if(check(m)) {
            c=m-1;
            rs=m;
        }
        else d=m+1;
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