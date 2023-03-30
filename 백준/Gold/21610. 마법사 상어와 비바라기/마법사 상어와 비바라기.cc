#include <bits/stdc++.h>
using namespace std;
int board[51][51];
int n, m;
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
queue<pair<int, int>> cloud, Q;
int cx[4] = { -1, -1, 1, 1 };
int cy[4] = { -1, 1, 1, -1 };
bool before_cloud[51][51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	cloud.push({n, 1});
	cloud.push({ n, 2 });
	cloud.push({ n - 1, 1 });
	cloud.push({ n - 1, 2 });

	while (m--) {

		for (int i = 1; i <= n; i++) {
			fill(before_cloud[i] + 1, before_cloud[i] + n + 1, false);
		}

		int d, s;
		cin >> d >> s;
		while (!cloud.empty()) {
			int x, y;
			tie(x, y) = cloud.front();
			cloud.pop();
			for (int i = 0; i < s; i++) {
				x += dx[d];
				y += dy[d];
				x = (x + (n - 1)) % n + 1;
				y = (y + (n - 1)) % n + 1;
			}
			board[x][y]++;
			Q.push({ x, y });
		}

		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();
			before_cloud[x][y] = true;

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + cx[dir];
				int ny = y + cy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (board[nx][ny] > 0) board[x][y]++;
			}

		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] >= 2 && !before_cloud[i][j]) {
					cloud.push({ i, j });
					board[i][j] -= 2;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += board[i][j];
		}
	}

	cout << cnt;
}