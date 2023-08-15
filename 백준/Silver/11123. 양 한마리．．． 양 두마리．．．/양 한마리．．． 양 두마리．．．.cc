#include <bits/stdc++.h>
using namespace std;
char board[100][100];
bool vis[100][100];

queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + m, false);
			for (int j = 0; j < m; j++) cin >> board[i][j];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '#' && !vis[i][j]) {
					Q.push({i, j});
					vis[i][j] = true;
					cnt++;
					while (!Q.empty()) {
						int x, y;
						tie(x, y) = Q.front();
						Q.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = x + dx[dir];
							int ny = y + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (board[nx][ny] == '.' || vis[nx][ny]) continue;

							vis[nx][ny] = true;
							Q.push({nx, ny});
						}
					}
				}
			}

		}
			cout << cnt << '\n';
	}
}