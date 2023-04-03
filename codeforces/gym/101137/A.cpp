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
int L[N],R[N];
void prepare1() {
    deque<int> deq;
    fto(i,1,n*2) {
        while(!deq.empty()&&a[deq.back()]>=a[i])
        deq.pop_back();
        if(deq.empty()) L[i]=-1;
        else L[i]=deq.back();
        deq.push_back(i);
    }
}
void prepare2() {
    deque<int> deq;
    fdo(i,n*2,1) {
        while(!deq.empty()&&a[deq.front()]>=a[i])
        deq.pop_front();
        if(deq.empty()) R[i]=n*2+1;
        else R[i]=deq.front();
        deq.push_front(i);
    }
}
void Solve() {
    cin>>n;
    fto(i,1,n) cin>>a[i];
    fto(i,n+1,n*2) a[i]=a[i-n];
    prepare1();
    prepare2();
    int rs=10*n;
    int pos;
    fto(i,1,n*2) {
        if(L[i]!=-1&&R[i]!=n*2+1)
        if(rs>abs(i-L[i])+abs(R[i]-i))
        {
            rs=min(rs,abs(i-L[i])+abs(R[i]-i));
            pos=i;
        }
    } 
    if(L[pos]%n==0) cout<<n<<' '; else cout<<L[pos]%n<<' ';
    if(pos%n==0) cout<<n<<' '; else cout<<pos%n<<' ';
    if(R[pos]%n==0) cout<<n<<' '; else cout<<R[pos]%n<<' ';

}
int32_t main() {

    if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int Test;
    Test=1;
    fto(iTest,1,Test) {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}