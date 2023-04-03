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

int n,m;
int a[N];
string st;
int Power(int aa,int bb){
    if(bb==0) return 1;
    if(bb==1) return aa%inf;
    int cc=Power(aa,bb/2);
    cc=(cc*cc)%inf;
    if(bb%2==1){
        return (cc*aa)%inf;
    }
    return cc%inf;
}
void Solve() {
    cin>>n>>m;
    cin>>st;
    st=' '+st;
    int cc=0;
    int cnt=0;
    fto(i,1,n) {
        cc=(cc*10+st[i]-'0')%m;
        if(cc==0) {
            cnt++;
        }
    }
    if(cnt==0||cc!=0) {
        cout<<0;
        return ;
    }
    cout<<Power(2,cnt-1);
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