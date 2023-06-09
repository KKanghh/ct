#include <bits/stdc++.h>
using namespace std;
char board[100][100];
int dist[100][100];
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> Q;
int tx, ty;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			dist[i][j] = -1;
			cin >> board[i][j];
			if (board[i][j] == 'C') {
				if (Q.empty()) {
					Q.push({ i, j });
					dist[i][j] = 0;
				}
				else {
					tx = i, ty = j;
				}
			}
		}
	}

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			while (nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] != '*' && (dist[nx][ny] >= dist[x][y] + 1 || dist[nx][ny] == -1)) {
				if (dist[nx][ny] != dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					Q.push({ nx, ny });
				}
				nx += dx[dir];
				ny += dy[dir];
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 'C') cnt += dist[i][j];
			//if (dist[i][j] == -1) cout << '*' << ' ';
			//else cout << dist[i][j] << ' ';
		}
		//cout << '\n';
	}

	cout << cnt - 1;
}