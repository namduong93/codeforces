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

int n,m,k;
int a[N],D[N];
string st;
priority_queue< pii, vector<pii>, greater<pii> >pq;
void Solve() {
    cin>>n>>m>>k;
    int sz=n/m;
    int nBig=n%m;
    while(pq.size()) pq.pop();
    fto(i,1,n) {pq.push({0,i});D[i]=0;}
    fto(i,1,k) {
        //if(k==2) cout<<pq.top().se;
        if(nBig) {
            fto(x,1,nBig)
            {
                cout<<sz+1<<' ';
                fto(j,1,sz+1) {
                    cout<<pq.top().se<<' ';
                    D[pq.top().se]++;
                    pq.pop();
                }
                cout<<'\n';
            }
        }
        fto(x,1,m-nBig) 
        {
            cout<<sz<<' ';
            fto(j,1,sz) {
                cout<<pq.top().se<<' ';
                pq.pop();
            }
            cout<<'\n';
        }
        fto(i,1,n) pq.push({D[i],i});
    }
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