#include <bits/stdc++.h>
using namespace std;
int board[2000][2000];
bool sit[2000][2000];
queue<tuple<int, int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				sit[i][j] = true;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					Q.push({ nx, ny, dir });
					sit[nx][ny] = true;
				}
			}
		}
	}

	while (!Q.empty()) {
		int x, y, h;
		tie(x, y, h) = Q.front();
		Q.pop();
		if ((h == 0 || h == 2) && board[x][y] == 1) continue;
		if ((h == 1 || h == 3) && board[x][y] == 2) continue;
		if (board[x][y] == 3) h = 3 - h;
		if (board[x][y] == 4) h = (h / 2) * 2 + 1 - h % 2;

		int nx = x + dx[h];
		int ny = y + dy[h];

		if (nx < 0 || nx >= n || y < 0 || ny >= m) continue;
        if (board[nx][ny] == 9) continue;

		Q.push({ nx, ny, h });
		sit[nx][ny] = true;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sit[i][j]) cnt++;
		}
	}

	cout << cnt;
}