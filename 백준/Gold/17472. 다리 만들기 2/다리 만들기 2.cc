#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[7];
int dist[7][7];
int board[10][10];
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, m, ans;
bool vis[7];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


void func(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		int len = 0;
		while (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0) {
			len++;
			nx += dx[dir];
			ny += dy[dir];
		}
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (board[x][y] == board[nx][ny] || len <= 1) continue;
		dist[board[x][y]][board[nx][ny]] = min(dist[board[x][y]][board[nx][ny]], len);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) board[i][j] = -1;
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] >= 0) continue;
			board[i][j] = ++cnt;
			Q.push({ i, j });

			while (!Q.empty()) {
				int x, y;
				tie(x, y) = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] >= 0) continue;
					board[nx][ny] = board[x][y];
					Q.push({ nx, ny });
				}
			}
		}
	}

	for (int i = 1; i <= cnt; i++) {
		fill(dist[i] + 1, dist[i] + cnt + 1, 0x3f3f3f3f);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			func(i, j);
		}
	}

	vis[1] = true;
	for (int i = 1; i <= cnt; i++) {
		if (dist[1][i] == 0x3f3f3f3f) continue;
		pq.push({ dist[1][i], i });
	}

	while (!pq.empty()) {
		int len, v;
		tie(len, v) = pq.top();
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		ans += len;

		for (int i = 1; i <= cnt; i++) {
			if (vis[i] || dist[v][i] == 0x3f3f3f3f) continue;
			pq.push({ dist[v][i], i });
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (!vis[i]) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}