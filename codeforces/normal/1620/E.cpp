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
const int N=1000005;
const int inf =1e9+7;

unordered_map<int,int> a;
string st;
pair<int,pii> Query[N];
stack<int> sta;
void Solve() {
    int q;
    cin>>q;
    fto(i,1,q) {
        int ch,x,y;
        cin>>ch;
        if(ch==1) {
            cin>>x;
            Query[i]={ch,{x,0}};
        }
        else {
            cin>>x>>y;
            Query[i]={ch,{x,y}};
        }
    }
    fdo(i,q,1) {
        if(Query[i].fi==1) {
            int t1=Query[i].se.fi;
            if(a[t1]==0) sta.push(t1);
            else sta.push(a[t1]);
        }
        else {
            if(a[Query[i].se.se]==0)
            a[Query[i].se.fi]=Query[i].se.se;
            else a[Query[i].se.fi]=a[Query[i].se.se];
        }
        //if(i==5) cout<<a[2];
    }
    while(!sta.empty()) {
        cout<<sta.top()<<' ';
        sta.pop();
    }
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