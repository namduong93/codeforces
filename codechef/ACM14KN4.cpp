/**
 *    author:  namduong93
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
const int N = 100005;
const int inf = 1e9 + 7;

int n;
int a[N];
string str;
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

struct node {
    int Max = 0;
    long long Sum = 0;
    bool In = false;
    bool De = false;
    bool valid = false;
};

node Tree[4*N];

void build(int x, int l, int r) {
    if(l == r) {
        Tree[x].Max = a[l];
        Tree[x].Sum = a[l];
        Tree[x].In = true;
        Tree[x].De = true;
        Tree[x].valid = true;
        return ;
    }
    build(x * 2, l, (l+r) / 2);
    build(x * 2 + 1, (l + r) / 2 + 1, r);
    Tree[x].Max = max(Tree[x * 2].Max, Tree[x * 2 + 1].Max);
    Tree[x].Sum = Tree[x * 2].Sum + Tree[x * 2 + 1].Sum;
    Tree[x].In = ((Tree[x * 2].In & Tree[x * 2 + 1].In) & (a[(l + r) / 2] <= a[(l + r) / 2 + 1]));
    Tree[x].De = ((Tree[x * 2].De & Tree[x * 2 + 1].De) & (a[(l + r) / 2] >= a[(l + r) / 2 + 1]));
    Tree[x].valid = true;
}

node get(int x, int l, int r, int d, int c) {
    node tmp;
    if(c < l || r < d) {
        return tmp;
    }
    if(d <= l && r <= c) {
        return Tree[x];
    }
    node left = get(x * 2, l, (l + r) / 2, d, c);
    node right = get(x * 2 + 1, (l + r) / 2 + 1, r, d, c);
    if(left.valid == false) {
        return right;
    }
    if(right.valid == false) {
        return left;
    }
    node new_node;
    new_node.Max = max(left.Max, right.Max);
    new_node.Sum = left.Sum + right.Sum;
    new_node.In = ((left.In & right.In) & (a[(l + r) / 2] <= a[(l + r) / 2 + 1]));
    new_node.De = ((left.De & right.De) & (a[(l + r) / 2] >= a[(l + r) / 2 + 1]));
    new_node.valid = true;
    return new_node;
}

void update(int x, int l, int r, int u, int val) {
    node tmp;
    if(u < l || r < u) {
        return ;
    }
    if(u == l && u == r) {
        Tree[x].Max = val;
        Tree[x].Sum = val;
        Tree[x].In = true;
        Tree[x].De = true;
        Tree[x].valid = true;
        return;
    }
    update(x * 2, l, (l+r) / 2, u, val);
    update(x * 2 + 1, (l + r) / 2 + 1, r, u, val);
    Tree[x].Max = max(Tree[x * 2].Max, Tree[x * 2 + 1].Max);
    Tree[x].Sum = Tree[x * 2].Sum + Tree[x * 2 + 1].Sum;
    Tree[x].In = ((Tree[x * 2].In & Tree[x * 2 + 1].In) & (a[(l + r) / 2] <= a[(l + r) / 2 + 1]));
    Tree[x].De = ((Tree[x * 2].De & Tree[x * 2 + 1].De) & (a[(l + r) / 2] >= a[(l + r) / 2 + 1]));
    Tree[x].valid = true;
    return;
}
void Solve()
{
    int m;
    cin >> n >> m;
    fto(i, 1, n) {
        cin >> a[i];
    }
    build(1, 1, n);
    fto(i, 1, m) {
        char ch;
        int x,y;
        cin >> ch >> x >> y;
        if(ch == 'U') {
            a[x] = y;
            update(1, 1, n, x, y);
        }
        if(ch == 'M') {
            cout << get(1, 1, n, x, y).Max << '\n';
        }
        if(ch == 'S') {
           cout << get(1, 1, n, x, y).Sum << '\n';
        }
        if(ch == 'I') {
            cout << get(1, 1, n, x, y).In << '\n';
        }
        if(ch == 'D') {
            cout << get(1, 1, n, x, y).De << '\n';
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
    // cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}