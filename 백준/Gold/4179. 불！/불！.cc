#include <bits/stdc++.h>
using namespace std;
char board[1000][1000];
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int fire[1000][1000], jihun[1000][1000]; // 1000000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'F') {
				Q.push({ i, j });
				fire[i][j] = 1;
			}
		}
	}

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (fire[nx][ny] > 0 || board[nx][ny] == '#') continue;

			fire[nx][ny] = fire[x][y] + 1;
			Q.push({ nx, ny });
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				Q.push({ i, j });
				jihun[i][j] = 1;
			}
		}
	}

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << jihun[x][y];
				return 0;
			}
			if (board[nx][ny] == '#' || (jihun[x][y] + 1) >= fire[nx][ny] && fire[nx][ny] > 0 || jihun[nx][ny] > 0) continue;

			jihun[nx][ny] = jihun[x][y] + 1;
			Q.push({ nx, ny });
		}
	}

	

	cout << "IMPOSSIBLE";
}