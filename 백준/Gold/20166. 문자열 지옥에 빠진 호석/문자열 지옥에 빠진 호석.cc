#include <bits/stdc++.h>
using namespace std;
char board[10][10];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
map<string, int> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	string sin;
	for (int i = 0; i < k; i++) {
		cin >> sin;
		if (ans.count(sin)) {
			cout << ans[sin] << '\n';
			continue;
		}
		int len = sin.length();
		int cnt = 0;
		stack<tuple<int, int, int>> Q;

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (board[x][y] == sin[0]) {
					Q.push({ x, y, 0 });
				}
			}
		}

		while (!Q.empty()) {
			int x, y, t;
			tie(x, y, t) = Q.top();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0) nx += n;
				if (nx >= n) nx -= n;
				if (ny < 0) ny += m;
				if (ny >= m) ny -= m;

				if (board[nx][ny] == sin[t + 1]) {
					if (t + 1 == len - 1) cnt++;
					else {
						Q.push({ nx, ny, t + 1 });
					}
				}
			}
		}
		ans[sin] = cnt;
		cout << cnt << '\n';
	}
}