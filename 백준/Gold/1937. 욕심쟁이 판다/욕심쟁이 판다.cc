#include <bits/stdc++.h>
using namespace std;
int board[500][500];
bool vis[500][500];
int D[500][500];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n;

void func(int x, int y) {
	if (vis[x][y]) return;
	vis[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (board[nx][ny] <= board[x][y]) continue;

		func(nx, ny);
		D[x][y] = max(D[x][y], D[nx][ny] + 1);
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			func(i, j);
		}
	}

	int mx = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mx = max(mx, D[i][j]);
		}
	}

	cout << mx + 1;
}