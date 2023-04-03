/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    Yu nhau chng n vi nhau
 *    Ngi ta vn hn kip sau s ch
 *    Ngha trang sng khi mt m
 *    Kip ny khng c ng ch kip sau
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdo(i, a, b) for (int i = a; i >= b; --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())

int getBit(int x, int i)
{
    return x & (1 << i);
}
int turnBit(int x, int i) { return x | (1 << i); }
int swapBit(int x, int i) { return x ^ (1 << i); }

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 300005;
const int inf = 1e9 + 7;

int n;
int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
multiset<int> ms;
int dp[N][4][2][2];
int rs;

void Solve()
{
  cin >> n;
  fto(i,1,n) {
    cin>>a[i];
  }
  if (a[1])
  dp[1][a[1]][0][0] = 1;
  //cout<<rs;

  fto(i,2,n) {
    fto(j,1,3) {
      fto(k,0,1) {
        fto(l,0,1) {
          if (!a[i])
            dp[i][j][k][l] = dp[i - 1][j][k][l];
          if(a[i] && !(j & a[i]))
            dp[i][j][k or a[i] == 1][l or a[i] == 2] += dp[i - 1][j][k][l];
          if(a[i] && (j & a[i]))
            dp[i][a[i]][k][l] += dp[i - 1][j][k][l];
        }
      }
    }
    if (a[i]) {
      int run = i;
      run--;
      while(run >= 1 && (!a[run]))
        run -= 1; 
      dp[i][a[i]][0][0] += (i - run);
    }
  }
  
  //for(int i = 1; i <= n; ++i)for(int gg = 0; gg <= 4; gg++) for(int j = 0; j <= 2; j++) for(int k = 0; k<= 2; ++k)
  //cout<<dp[i][gg][j][k]<<'\n';

  fto(i,1,n)
    fto(j,1,3)
      fto(k,0,1)
        fto(l,0,1)
          rs += dp[i][j][k][l] * (k + l + 1);
  fto(i,1,n) {
        if(!a[i]) rs += (i ) * (n-i + 1);
 }
  cout << rs << '\n';

}

int32_t main()
{

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Test = 1;
    //cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}