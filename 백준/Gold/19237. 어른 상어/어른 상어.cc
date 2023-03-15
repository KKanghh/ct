#include <bits/stdc++.h>
using namespace std;
int board[20][20];
pair<int, int> smellboard[20][20];
int n, m, k;
pair<int, int> smell[1001][401];
pair<int, int> p[401];
int head[401];
int priority[401][5][4];
int dx[5] = {0, -1, 1, 0 ,0 };
int dy[5] = {0, 0, 0, -1, 1 };
bool alive[401];

int decide(int shark) {
	int x, y;
	tie(x, y) = p[shark];
	for (int dir : priority[shark][head[shark]]) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (smellboard[nx][ny].first == 0) return dir;
	}
	for (int dir : priority[shark][head[shark]]) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (smellboard[nx][ny].first == shark) return dir;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt;
	
	cin >> n >> m >> k;
	cnt = m;
	fill(alive + 1, alive + m + 1, true);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			p[board[i][j]] = { i, j };
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> head[i];
	}


	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> priority[i][j][k];
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		smell[0][i].first = p[i].first;
		smell[0][i].second = p[i].second;
		smellboard[p[i].first][p[i].second].first = i;
	}

	int time = 0;
	while (true) {
		time++;
		if (time > 1000) break;
		for (int i = 1; i <= m; i++) {
			if (!alive[i]) continue;
			head[i] = decide(i);
			int x, y;
			tie(x, y) = p[i];
			int nx = x + dx[head[i]];
			int ny = y + dy[head[i]];

			board[x][y] = 0;
			p[i] = { nx, ny };

		}

		for (int i = 1; i <= m; i++) {
			if (!alive[i]) continue;
			int x, y;
			tie(x, y) = p[i];
			if (board[x][y] > 0 && board[x][y] < i) {
				alive[i] = false;
				cnt--;
				continue;
			}
			board[x][y] = i;
		}

		for (int i = 1; i <= m; i++) {
			if (!alive[i]) continue;
			int x, y;
			tie(x, y) = p[i];
			smellboard[x][y] = { i, time };
			smell[time][i] = { x, y };
		}

		if (time >= k) {
			for (int i = 1; i <= m; i++) {
				if (smellboard[smell[time - k][i].first][smell[time - k][i].second].second == time - k) {
					smellboard[smell[time - k][i].first][smell[time - k][i].second] = { 0, 0 };
				}
			}
		}

		if (cnt == 1) {
			cout << time;
			return 0;
		}
	}

	cout << -1;
}