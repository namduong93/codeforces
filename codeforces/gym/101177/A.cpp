/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
**/
#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
const int N = 200005;
const int inf = 1e9 + 7;

int n;
int a, b;
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
multiset<int> ms;

pair<int,int> Check(int st, int num) {
    int controlRange = 0;
    int newSt = st;
    int jump = st - 1;
    if(num == 1) return {0,0};
    int Max, Min;
    while(1) {
        controlRange ++;
        if(st == 2) {
            Max = newSt + controlRange;
            Min = newSt - controlRange + 1;
        }
        else {
            Max = newSt + controlRange;
            Min = newSt - controlRange;
        }
        if(Min > num) {
            return {- 1e9, - 1e9};
        }
        
        if(Min <= num && num <= Max) {
            if(newSt >= num) {
                if(st == 2) {
                    return {0 - (newSt - num), - controlRange};
                }
                if(st == 4) {
                    return {controlRange, 0 - (newSt - num)};
                }
                if(st == 6) {
                    return {newSt - num, controlRange};
                }
                if(st == 8) {
                    return {-controlRange, newSt - num};
                }
            }
            else {
                if(st == 2) {
                    return {0 - (newSt - num), - controlRange};
                }
                if(st == 4) {
                    return {controlRange, 0 - (newSt - num)};
                }
                if(st == 6) {
                    return {newSt - num, controlRange};
                }
                if(st == 8) {
                    // cout<<-controlRange << ' ';
                    return {-controlRange, newSt - num};
                }
            }
        }
        jump += 8;
        newSt += jump;
    }
}

void Solve()
{
    cin >> a >> b;

    pair <int,int> resultA = {- 1e9, - 1e9};
    resultA = max(resultA, Check(2, a));
    resultA = max(resultA, Check(4, a));
    resultA = max(resultA, Check(6, a));
    resultA = max(resultA, Check(8, a));

    pair <int,int> resultB = {- 1e9, - 1e9};
    resultB = max(resultB, Check(2, b));
    resultB = max(resultB, Check(4, b));
    resultB = max(resultB, Check(6, b));
    resultB = max(resultB, Check(8, b));
    // cout << resultA.fi << ' ' << resultA.se<<' ';
    // cout << resultB.fi << ' ';
    cout << abs(resultA.fi - resultB.fi) + abs(resultA.se - resultB.se);
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

    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}