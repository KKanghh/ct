#include <bits/stdc++.h>
using namespace std;

int board[15][15], temp_board[15][15];
int mx, n, m, d, enemy, kill_cnt, out_cnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

tuple<int, int, int> arc(int a, int b) {
	queue<pair<int, int>> Q;
	tuple<int, int, int> mn = { 0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f };
	int dist[16][15] = {-1};
	dist[a][b] = 0;
	Q.push({ a, b });
	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();
		if (dist[x][y] >= get<0>(mn)) break;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] > 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			if (temp_board[nx][ny] == 1) mn = min(mn, { dist[nx][ny], ny, nx });
			if (dist[nx][ny] < d) Q.push({ nx, ny });
		}
	}

	return mn;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) enemy++;
		}
	}

	vector<bool> V(m, true);
	fill(V.begin(), V.begin() + 3, false);


	do {
		vector<int> archor;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) temp_board[i][j] = board[i][j];
		}
		kill_cnt = 0;
		out_cnt = 0;

		while (enemy > kill_cnt + out_cnt) {
			set<pair<int, int>> tokill;
			for (int i = 0; i < m; i++) {
				if (!V[i]) {
					auto k = arc(n, i);
					int far, x, y;
					tie(far, y, x) = k;
					if (far == 0x3f3f3f3f) continue;
					tokill.insert({ x, y });
				}
			}
			for (auto e : tokill) {
				temp_board[e.first][e.second] = 0;
				kill_cnt++;
			}
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < m; j++) {
					if (temp_board[i][j] == 1) {
						if (i + 1 == n) {
							temp_board[i][j] = 0;
							out_cnt++;
						}
						else {
							temp_board[i][j] = 0;
							temp_board[i + 1][j] = 1;
						}
					}
				}
			}
		}
		mx = max(mx, kill_cnt);

	} while (next_permutation(V.begin(), V.end()));

	cout << mx;
}