#include <bits/stdc++.h>
using namespace std;
int board[64][64];
bool vis[64][64];
int n;
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void dfs(int x, int y) {
	if (x == n - 1 && y == n - 1) return;

	for (int dir = 0; dir < 2; dir++) {
		int nx = x + dx[dir] * board[x][y];
		int ny = y + dy[dir] * board[x][y];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (vis[nx][ny]) continue;

		vis[nx][ny] = true;
		dfs(nx, ny);
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0);
	if (vis[n - 1][n - 1]) cout << "HaruHaru";
	else cout << "Hing";
}