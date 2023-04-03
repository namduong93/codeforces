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

int n,a[N];
string st;
int b[20];
void Solve() {
    n=7;
    vector<int> tmp;
    fto(i,1,n) {cin>>b[i];tmp.push_back(b[i]);}
    sort(tmp.begin(),tmp.end());
    fto(i,1,n) {
        fto(j,i+1,n)
            fto(k,j+1,n) {
                vector<int> rs;
                rs.push_back(b[i]);
                rs.push_back(b[j]);
                rs.push_back(b[k]);
                rs.push_back(b[i]+b[j]);
                rs.push_back(b[j]+b[k]);
                rs.push_back(b[i]+b[k]);
                rs.push_back(b[i]+b[j]+b[k]);
                sort(rs.begin(),rs.end());
                if(rs==tmp) {
                    cout<<b[i]<<' '<<b[j]<<' '<<b[k]<<'\n';
                    return ;
                }
            }
    }
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