#include <bits/stdc++.h>
using namespace std;
char board[50][50];
int dist[50][50];
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int mx = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'W') continue;

			for (int k = 0; k < n; k++) {
				fill(dist[k], dist[k] + m, -1);
			}

			dist[i][j] = 0;
			Q.push({ i, j });

			while (!Q.empty()) {
				int x, y;
				tie(x, y) = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 'W' || dist[nx][ny] >= 0) continue;
					dist[nx][ny] = dist[x][y] + 1;
					mx = max(dist[nx][ny], mx);
					Q.push({ nx, ny });
				}
			}
		}
	}

	cout << mx;
}