#include <bits/stdc++.h>
using namespace std;
int board[1000][1000];
int cnt[1000][1000];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char t;
			cin >> t;
			if (t == '.') {
				board[i][j] = 0;
				for (int dir = 0; dir < 8; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
					cnt[nx][ny]++;
				}
			}
			else board[i][j] = t - '0';
		}
	}
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++) {
			if (board[x][y] > 0 && board[x][y] <= cnt[x][y]) {
				Q.push({x, y});
			}
		}
	}

	int wave = 0;
	while (!Q.empty()) {
		queue<pair<int, int>> tq;
		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();

			board[x][y] = 0;
			for (int dir = 0; dir < 8; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

				cnt[nx][ny]++;
				if (board[nx][ny] > 0 && board[nx][ny] == cnt[nx][ny]) tq.push({nx, ny});
			}
		}
		
		Q = tq;
		
		wave++;
	}

	cout << wave;
}