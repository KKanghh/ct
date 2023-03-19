#include <bits/stdc++.h>
using namespace std;
int board[64][64];
bool vis[64][64];
queue<int> Q;
queue<pair<int, int>> FQ, melt;
int ans, mx;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int m = 1;
	for (int i = 0; i < n; i++) m *= 2;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;

	while (cnt++ < q) {
		int l;
		cin >> l;
		int sz = 1;
		for (int i = 0; i < l; i++) sz *= 2;
		for (int x = 0; x < m; x += sz) {
			for (int y = 0; y < m; y += sz) {

				for (int i = x; i < x + sz; i++) {
					for (int j = y; j < y + sz; j++) {
						Q.push(board[i][j]);
					}
				}

				
				for (int j = y + sz - 1; j >= y; j--) {
					for (int i = x; i < x + sz; i++) {
						board[i][j] = Q.front();
						Q.pop();
					}
				}

			}
		}

		for (int x = 0; x < m; x++) {
			for (int y = 0; y < m; y++) {
				if (board[x][y] == 0) continue;
				int ice = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					
					if (nx < 0 || nx >= m || ny < 0 || ny >= m || board[nx][ny] == 0) continue;
					ice++;
				}

				if (ice < 3) melt.push({x, y});
			}
		}

		while (!melt.empty()) {
			int x, y;
			tie(x, y) = melt.front();
			melt.pop();
			board[x][y]--;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] > 0 && !vis[i][j]) {
				int S = 0;
				FQ.push({ i, j });
				vis[i][j] = true;
				while (!FQ.empty()) {
					int x, y;
					tie(x, y) = FQ.front();
					ans += board[x][y];
					S++;
					FQ.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis[nx][ny]) continue;
						FQ.push({ nx, ny });
						vis[nx][ny] = true;
					}
				}
				mx = max(mx, S);
			}
		}
	}

	cout << ans << '\n' << mx;
}