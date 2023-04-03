/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 *    i miss Vn
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

int a[N];
string st;
priority_queue<pii, vector<pii>, greater<pii>> dHeap;
multiset<int> ms;

int n;
string ORstring(string st1, string st2) {
    int len1 = st1.length() - 1;
    int len2 = st2. length() - 1;
    while(len1 >= 0 && len2 >= 0) {
        if(st1[len1] != '1') {
            if(st2[len2] == '1') st1[len1] = '1';
        }
        len1--;
        len2--;
    }
    return st1;
}
void Solve()
{
    cin>>n;
    cin>>st;
    
    int run = 0;
    while(st.length() && st[0] == '0') {
        st.erase(0,1);
    }
    if(st=="") {
        cout<<0;
        return ;
    }
    string ans = st;
    int pos1 = st.find('1');
    if(pos1 != -1) {
        int pos2 = st.find('0');
        n = st.length();
        if(pos2 != -1)
        {
            int xx = pos2 - pos1;
            fdo(i,n - 1,n - 1 - xx) {
                string cc = st.substr(pos1, i + 1);
                cc = ORstring(st,cc);
                ans = max(ans, cc);
            }
            cout<<ans;
        }
        else {
            cout<<st;
            return ;
        }
    }
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