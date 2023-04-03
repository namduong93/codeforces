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
const int N=1e6+5;
const int inf =1e9+7;

const int dx[4]={-1,0,0,1};
const int dy[4]={0,1,-1,0};
int n,m;
vector<char> ch[N];
string st;
int La,Lb;
vector<int> vis[N];
void dfs(int u,int v) {
    vis[u][v]=true;
    fto(t,0,3) {
        int uu=u+dx[t];
        int vv=v+dy[t];
        if(uu>=1&&uu<=n&&vv>=1&&vv<=m&&vis[uu][vv]==false&&ch[uu][vv]=='.') {
            int cnt=0;
            fto(t,0,3) {
                int uuu=uu+dx[t];
                int vvv=vv+dy[t];
                if(uuu>=1&&uuu<=n&&vvv>=1&&vvv<=m&&ch[uuu][vvv]=='.') {
                    if(vis[uuu][vvv]==false)
                        cnt++;
                }
            }
            if(cnt==1||cnt==0) dfs(uu,vv);
        }
    }
}
void Solve() {
    cin>>n>>m;
    fto(i,1,n) {
        ch[i].resize(m+1);
        vis[i].resize(m+1);
        cin>>st;
        fto(j,1,m)
        {
            ch[i][j]=st[j-1];
            if(ch[i][j]=='L') {
                La=i;
                Lb=j;
            }
        }
    }
    vis[La][Lb]=true;
    dfs(La,Lb);
    fto(i,1,n) fto(j,1,m) {
        if(ch[i][j]=='#'||ch[i][j]=='L') cout<<ch[i][j];
        else
            if(vis[i][j]==true)
            cout<<'+';
            else cout<<'.';
        if(j==m) 
        cout<<'\n';
    }
    fto(i,1,n) fto(j,1,m) vis[i][j]=false;
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

  return 0;
}