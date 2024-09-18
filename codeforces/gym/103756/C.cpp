/**
 *    author:  Nam Duong
 *    created: unknown
 *    complexity: unknown
 **/
#include <bits/stdc++.h>
using namespace std;

#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdo(i, a, b) for (int i = a; i >= b; --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())

int get_bit(int x, int i)
{
    return x & (1 << i);
}
int turn_bit(int x, int i) { return x | (1 << i); }
int swap_bit(int x, int i) { return x ^ (1 << i); }

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 3001;
const int inf = 1e9 + 7;

int n;
int a[N + 1][N + 1], tmp_Q[N][N], sum[N][N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

int find(int m, int a[3002][3002], int R, int C, int H, int W) {
    fto(i,1,R)
    fto(j,1,C) {
        if(a[i][j] == m) tmp_Q[i][j] = 0;
        if(a[i][j] < m) tmp_Q[i][j] = -1;
        if(a[i][j] > m) tmp_Q[i][j] = 1;
    }
    fto(i,1,R) {
        fto(j,1,C) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + tmp_Q[i][j];
        }
    }
    bool exist = false;
    fto(i,H,R) fto(j,W,C) {
        int guess = sum[i][j] - sum[i - H][j] - sum[i][j - W] + sum[i - H][j - W];
        if(guess < 0) return -1;
        if (guess == 0) exist = true;
    }
    if(exist) return 0;
    return 1;
}

int rectangle(int R, int C, int H, int W, int Q[3001][3001])
{
    fto(i, 1, R)
    fto(j, 1, C) {
        a[i][j] = Q[i - 1][j - 1];
    }
    int l = 1;
    int r = R*C;
    int result = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        int tmp = find(m, a, R, C, H, W);
        if(tmp == 0) {
            result = m;
        }
        if(tmp <= 0) {
            r = m - 1;
        } else l = m + 1;
    }
    return result;
}

// static int R,C,H,W,Q[3001][3001],i,j,ans;
// int main(){
//    scanf("%d%d%d%d",&R,&C,&H,&W);
//    for (i=0;i<R;i++) 
//    for (j=0;j<C;j++) 
//    scanf("%d",&Q[i][j]);
//    ans = rectangle(R,C,H,W,Q);
//    printf("%d\n",ans);
//    return 0;
// }
