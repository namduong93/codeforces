/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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

int n,k;
int a[N];
string st;
int sum;
bool check(int x) {
    int sum1=sum;
    if(sum1<=k) return true;
    if(sum1-x<=k) return true;
    int sumDown=0;
    fdo(i,n,2) {
        sumDown+=a[i];
        if(n-i+1>x) break;
        int cc=x-(n-i+1);
        if(sum-(sumDown+a[1]-(a[1]-cc)*(n-i+2))<=k) return true;
    }
    if(x>=n-1) {
        int a1=a[1]-(x-n+1);
        if(a1*n<=k) return true;
    }
    return false;
}
void Solve() {
    sum=0;
    cin>>n>>k;
    fto(i,1,n) {cin>>a[i];sum+=a[i];}
    sort(a+1,a+1+n);
    int d=0;
    int c=sum;
    int rs=sum;
    while(d<=c) {
        int mid=(d+c)/2;
        if(check(mid)) {
            rs=mid;
            c=mid-1;
        }
        else d=mid+1;
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