#include <bits/stdc++.h>
using namespace std;

int board[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[300][300];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = min(n, m) / 2;
	while (r--) {
		for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, false);

		for (int i = 0; i < cnt; i++) {
			int dir = 0;
			int x = i, y = i;
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int v = board[x][y];
			while (nx != i || ny != i) {
				// cout << nx << ' ' << ny << ' ' << i << '\n';
				swap(v, board[nx][ny]);
				vis[nx][ny] = true;
				x = nx;
				y = ny;
				nx = x + dx[dir];
				ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
					dir = (dir + 1) % 4;
					nx = x + dx[dir];
					ny = y + dy[dir];
				}
			}
			swap(v, board[nx][ny]);
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}