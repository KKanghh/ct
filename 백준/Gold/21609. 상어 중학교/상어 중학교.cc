#include <bits/stdc++.h>
using namespace std;
int board[20][20];
bool vis[20][20];
int n, m, ans;
queue<pair<int, int>> Q;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void gravity() {
	for (int x = n - 1; x >= 0; x--) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == m + 1 || board[x][y] == -1) continue;

			int nx = x;
			while (nx + 1 < n && board[nx + 1][y] == m + 1) nx++;
			swap(board[x][y], board[nx][y]);
		}
	}
}

void spin() {
	int temp[20][20] = {0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = board[j][n - 1 - i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = temp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		int cnt = 0;
		tuple<int, int, int, int> mx = {-1, -1, -1, -1};
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + n, false);
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] <= 0 || board[x][y] == m + 1) continue;
				int size = 1;
				queue<pair<int, int>> rainbow;
				vis[x][y] = true;
				Q.push({ x, y });
				while (!Q.empty()) {
					int cx, cy;
					tie(cx, cy) = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cx + dx[dir];
						int ny = cy + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] || (board[nx][ny] != 0 && board[nx][ny] != board[x][y])) continue;
						size++;
						if (board[nx][ny] == 0) rainbow.push({nx, ny});
						vis[nx][ny] = true;
						Q.push({ nx, ny });
					}
				}

				if (size < 2) continue;
				mx = max(mx, { size, rainbow.size(), x, y});
				while (!rainbow.empty()) {
					int x, y;
					tie(x, y) = rainbow.front();
					vis[x][y] = false;
					rainbow.pop();
				}
			}
		}

		if (get<0>(mx) == -1) break;

		int s, r, x, y;
		tie(s, r, x, y) = mx;
		int target = board[x][y];
		board[x][y] = m + 1;
		Q.push({ x, y });
		int plus = 1;

		while (!Q.empty()) {
			int cx, cy;
			tie(cx, cy) = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] != 0 && board[nx][ny] != target) continue;
				board[nx][ny] = m + 1;
				plus++;
				Q.push({ nx, ny });
			}
		}

		ans += plus * plus;
		gravity();
		spin();
		gravity();
	}

	cout << ans;

}