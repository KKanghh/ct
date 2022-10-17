#include <bits/stdc++.h>
using namespace std;
int board[50][50];
bool cleaned[50][50];
int N, M, x, y, dir, cnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool find = true;

	cin >> N >> M;
	cin >> x >> y >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int same_place = 0;
	while (true) {
		//cout << x << ' ' << y << ' ' << dir << '\n';
		same_place++;
		if (find && !cleaned[x][y]) {
			cleaned[x][y] = true;
			cnt++;
		}
		find = false;
		if (same_place == 5) {
			int nx = x + dx[(dir + 2) % 4];
			int ny = y + dy[(dir + 2) % 4];
			if (nx < 0 || nx >= N || ny >= M || ny < 0 || board[nx][ny] == 1) {
				cout << cnt;
				return 0;
			}
			x = nx, y = ny;
			same_place = 0;
			continue;
		}
		dir -= 1;
		if (dir < 0) dir += 4;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == 1) continue;
		if (!cleaned[nx][ny]) {
			x += dx[dir];
			y += dy[dir];
			find = true;
			same_place = 0;
		}
	}
}