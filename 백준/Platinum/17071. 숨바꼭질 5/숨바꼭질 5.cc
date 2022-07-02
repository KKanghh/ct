#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int lane[2][500001];
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	for (int i = 0; i < 2; i++) fill(lane[i], lane[i] + 500001, -1);
	cin >> N >> K;
	lane[0][N] = 0;
	Q.push({ 0, N });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int e : {cur.Y - 1, cur.Y + 1, 2 * cur.Y}) {
			if (e < 0 || e > 500000) continue;
			if (lane[(cur.X + 1) % 2][e] != -1) continue;
			lane[(cur.X + 1) % 2][e] =  cur.X + 1;
			Q.push({ cur.X + 1, e });
		}
	}

	int turn = 0;
	while (true) {
		K = K + turn;
		if (K > 500000) break;
		if (lane[turn % 2][K] <= turn && lane[turn % 2][K] != -1) {
			cout << turn;
			return 0;
		}
		turn = turn + 1;
	}

	cout << -1;
}