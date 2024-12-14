#include<bits/stdc++.h>
#define int 			long long
#define FOR(i, a, b)	for (int i = a; i <= (int) b; ++i)
#define FORD(i, a, b)	for (int i = a; i >= (int) b; --i)
#define REP(i, a, b)	for (int i = a; i <  (int) b; ++i)
using namespace std;

typedef pair<int, int> ii;

const int N = 204, K = 1004, MOD = 1e9 + 7;
int n, k, a[N];

void Add(int &a, int b) { a %= MOD; b %= MOD; a = (a+b) % MOD; }

int dp[2][N][K];

void sol() {
	sort(a+1, a+n+1);
	dp[0][0][0] = 1;

	int id = 1;
	REP(Time, 0, n) {
		id = 1-id;
		FOR(i, 0, n) FOR(j, 0, k) dp[1-id][i][j] = 0;

		FOR(i, 0, n) FOR(j, 0, k) {
			if (dp[id][i][j] == 0) continue;

			int nJ = j + i * (a[Time+1] - a[Time]);
			if (nJ > k) continue;
            if(Time == 2) cout << "Group:" << i << "Current imbalance" << j <<' ' << nJ<<'\n';

			Add( dp[1-id][i+1][nJ], dp[id][i][j] );
			Add( dp[1-id][i][nJ], dp[id][i][j] * (i+1) );
			if (i >= 1) Add( dp[1-id][i-1][nJ], dp[id][i][j] * i );
		}  
	}	

	int res = 0;
	FOR(i, 0, k) {
		Add( res, dp[1-id][0][i] );
	}
	cout << res << '\n';
}

#undef int
int main() {
#define int 			long long
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];

	sol();

	return 0;
}