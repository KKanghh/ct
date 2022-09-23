#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[500][500];
int D[500][500];
stack<pair<int, int>> S;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

int func(int x, int y) {
	if (D[x][y] != -1) return D[x][y];
	if (x == n - 1 && y == m - 1) return 1;
	D[x][y] = 0;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[x][y] > board[nx][ny]) {
			D[x][y] += func(nx, ny);
		}
	}

	return D[x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[0][0] = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fill(D[i], D[i] + m, -1);
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cout << func(0, 0);
}