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
bool cnt[30];
void Solve() {
    cin>>st;
    int cc=0;
    int day=1;
    fto(ch,0,'z'-'a') cnt[ch]=false;
    fto(i,0,st.length()-1){
        if(cnt[st[i]-'a']==false) {
            cc++;
            cnt[st[i]-'a']=true;
            if(cc==4) {
                day++;
                fto(ch,0,'z'-'a') cnt[ch]=false;
                cc=1;
                cnt[st[i]-'a']=true;
            }
        }
        //if(day==3) cout<<i;
    }
    cout<<day<<'\n';
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