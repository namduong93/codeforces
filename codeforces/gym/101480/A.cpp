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
string st[11]={
    "xxxxxx...xx...xx...xx...xx...xxxxxx","....x....x....x....x....x....x....x","xxxxx....x....xxxxxxx....x....xxxxx","xxxxx....x....xxxxxx....x....xxxxxx","x...xx...xx...xxxxxx....x....x....x","xxxxxx....x....xxxxx....x....xxxxxx","xxxxxx....x....xxxxxx...xx...xxxxxx","xxxxx....x....x....x....x....x....x","xxxxxx...xx...xxxxxxx...xx...xxxxxx","xxxxxx...xx...xxxxxx....x....xxxxxx",".......x....x..xxxxx..x....x......."
};
vector<string>v;
int a[2];
void Solve() {
    v.clear();
    fto(i,1,7) {
        string s;
        cin>>s;
        s=' '+s;
        if(v.size()==0) v.resize(s.length()/6+1);
        int cnt=5;
        int dem=1;
        fto(j,1,s.length()-1) {
            cnt--;
            v[dem]+=s[j];
            if(cnt==0) {
                cnt=5;
                dem++;
                j++;
            }
        }
    }
    int tt=0;
    a[0]=a[1]=0;
    fto(i,1,v.size()-1){
        int cc=0;
        fto(j,0,10)
        if(v[i]==st[j]) cc=j;
        if(cc!=10){
            a[tt]=a[tt]*10+cc;
        }
        else tt++;
    }
    int tmp=a[0]+a[1];
    vector<int> rs;
    while(tmp!=0){
        rs.push_back(tmp%10);
        tmp=tmp/10;
    }
    int cc=0;
    fto(i,1,7){
        fdo(j,rs.size()-1,0){
            fto(kk,0,4){
                cout<<st[rs[j]][cc*5+kk];
            }
            if(j!=0)
            cout<<'.';
        }
        cc++;
        cout<<'\n';
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