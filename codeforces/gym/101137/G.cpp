#include <bits/stdc++.h>
using namespace std;

int N;
bool edge[105][105];
int spare = 0;
int holds = -1;

void move(int from) {
    if (edge[spare][from] || spare == from) throw 20;
    edge[spare][from] = true;
    cout << from << " " << from << " " << spare << "\n";
    if (spare == 0) holds = from;
    spare = from;
}
 
void reset() {
    cout << 0 << " " << holds << " " << spare << "\n";
    holds = -1;
    spare = 0;
}


signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        move(i + 1);
        for (int step = 2; step < N - 1; ++step) {
            if (edge[i + 1][(i + step) % N + 1]) continue;
            //cout << step << "\n";
            for (int j = (i + step) % N; j != i; j = (j + step) % N) {
                move(j + 1);
            }
            move(i + 1);
        }
        //cout << "\n";
    }
    if (N > 2) {
        move(0 + 1);
        for (int i = N - 1; i > 0; --i) {
            move(i + 1);
        }
    }
    reset();
}