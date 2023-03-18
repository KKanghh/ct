#include <bits/stdc++.h>
using namespace std;
int board[499][499];
bool vis[499][499];
int dx[4] = { 0, 1 ,0 ,-1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int x = n / 2, y = n / 2;
	int dir = 0;
	int ans = 0;
	vis[x][y] = true;

	while (x != 0 || y != 0) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		vis[nx][ny] = true;

		int sand = board[nx][ny];
		board[nx][ny] = 0;

		int tx, ty;
		int t = sand;

		tx = x + dy[dir];
		ty = y + dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand / 100;
		else board[tx][ty] += sand / 100;
		t -= sand / 100;

		tx = x - dy[dir];
		ty = y - dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand / 100;
		else board[tx][ty] += sand / 100;
		t -= sand / 100;

		tx = x + dx[dir] + dy[dir];
		ty = y + dy[dir] + dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 7 / 100;
		else board[tx][ty] += sand * 7 / 100;
		t -= sand * 7 / 100;

		tx = x + dx[dir] - dy[dir];
		ty = y + dy[dir] - dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 7 / 100;
		else board[tx][ty] += sand * 7 / 100;
		t -= sand * 7 / 100;

		tx = x + dx[dir] + 2 * dy[dir];
		ty = y + dy[dir] + 2 * dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 2 / 100;
		else board[tx][ty] += sand * 2 / 100;
		t -= sand * 2 / 100;

		tx = x + dx[dir] - 2 * dy[dir];
		ty = y + dy[dir] - 2 * dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 2 / 100;
		else board[tx][ty] += sand * 2 / 100;
		t -= sand * 2 / 100;

		tx = x + 2 * dx[dir] + dy[dir];
		ty = y + 2 * dy[dir] + dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 10 / 100;
		else board[tx][ty] += sand * 10 / 100;
		t -= sand * 10 / 100;

		tx = x + 2 * dx[dir] - dy[dir];
		ty = y + 2 * dy[dir] - dx[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 10 / 100;
		else board[tx][ty] += sand * 10 / 100;
		t -= sand * 10 / 100;

		tx = x + 3 * dx[dir];
		ty = y + 3 * dy[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += sand * 5 / 100;
		else board[tx][ty] += sand * 5 / 100;
		t -= sand * 5 / 100;

		tx = x + 2 * dx[dir];
		ty = y + 2 * dy[dir];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) ans += t;
		else board[tx][ty] += t;
		x = nx;
		y = ny;
		
		if (!vis[x + dx[(dir + 1) % 4]][y + dy[(dir + 1) % 4]]) dir = (dir + 1) % 4;
	}

	

	cout << ans;

}