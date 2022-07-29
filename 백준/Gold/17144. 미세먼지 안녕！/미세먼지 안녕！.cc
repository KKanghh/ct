#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int R, C, T;
int board[50][50];
vector<pair<int, int>> V;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void expand() {
	int tmp[50][50] = {};
	for (auto e : V) {
		tmp[e.X][e.Y] = -1;
	}
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			if (board[x][y] > 0) {
				int m = board[x][y] / 5;
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if (board[nx][ny] == -1) continue;
					board[x][y] -= m;
					tmp[nx][ny] += m;
				}
				tmp[x][y] += board[x][y];
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

void purify() {
	int x, y;
	tie(x, y) = V[0];
	x--;
	while (x > 0) {
		board[x][y] = board[x - 1][y];
		x--;
	}
	while (y < C - 1) {
		board[x][y] = board[x][y + 1];
		y++;
	}
	while (x < V[0].X) {
		board[x][y] = board[x + 1][y];
		x++;
	}
	while (y > 1) {
		board[x][y] = board[x][y - 1];
		y--;
	}
	board[x][y] = 0;
	tie(x, y) = V[1];
	x++;
	while (x < R - 1) {
		board[x][y] = board[x + 1][y];
		x++;
	}
	while (y < C - 1) {
		board[x][y] = board[x][y + 1];
		y++;
	}
	while (x > V[1].X) {
		board[x][y] = board[x - 1][y];
		x--;
	}
	while (y > 1) {
		board[x][y] = board[x][y - 1];
		y--;
	}
	board[x][y] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) V.push_back({ i, j });
		}
	}

	while (T--) {
		expand();
		purify();
	}

	int ans = 2;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans += board[i][j];
		}
	}

	cout << ans;
}