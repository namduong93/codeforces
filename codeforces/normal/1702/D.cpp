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

int n,p;
int a[N];
string st;
int cnt[30];
void Solve() { 
    cin>>st;
    cin>>p;
    fto(i,0,'z'-'a') cnt[i]=0;
    int cal=0;
    fto(i,0,st.length()-1) {
        cnt[st[i]-'a']++;
        cal+=st[i]-'a'+1;
    }
    int run='z'-'a';
    while(cal>p) {
        if(cnt[run]) {
            cnt[run]--;
            cal-=run+1;
        }
        else run--;
    }
    fto(i,0,st.length()){
        if(cnt[st[i]-'a']) {cout<<st[i];cnt[st[i]-'a']--;}
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