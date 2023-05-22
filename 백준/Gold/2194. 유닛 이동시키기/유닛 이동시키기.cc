#include <bits/stdc++.h>
using namespace std;

int board[501][501], dist[501][501];
queue<pair<int, int>> Q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 501; i++) {
		fill(dist[i], dist[i] + 501, -1);
	}

	int n, m, a, b, k;
	cin >> n >> m >> a >> b >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		for (int p = 0; p < a; p++) {
			if (x - p <= 0) break;
			for (int q = 0; q < b; q++) {
				if (y + q > m) break;
				board[x - p][y + q] = 1;
			}
		}
	}
	
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	sy += b - 1;
	ey += b - 1;

	dist[sx][sy] = 0;
	Q.push({ sx, sy });

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx > n - a + 1 || nx <= 0 || ny < b || ny > m) continue;
			if (board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;

			dist[nx][ny] = dist[x][y] + 1;
			Q.push({ nx, ny });
		}
	}

	cout << dist[ex][ey];
	
}