#include<bits/stdc++.h>
using namespace std;
int board[21][21], st[21][21], en[21][21], dist[21][21];
pair<int, int> taxi;
queue<pair<int, int>> Q;
pair<int, int> passenger[401][2];
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	int cnt = m;

	cin >> taxi.first >> taxi.second;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		st[a][b] = i;
		passenger[i][0] = { a, b };
		cin >> a >> b;
		en[a][b] = i;
		passenger[i][1] = { a, b };
	}

	while (cnt > 0) {
		for (int i = 1; i <= n; i++) {
			fill(dist[i] + 1, dist[i] + n + 1, -1);
		}
		Q.push({ taxi.first, taxi.second });
		dist[taxi.first][taxi.second] = 0;
		vector<pair<int, int>> target;
		while (true) {
			queue<pair<int, int>> nxt;
			while (!Q.empty()) {
				int x, y;
				tie(x, y) = Q.front();
				if (st[x][y] > 0) target.push_back({ x, y });
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx <= 0 || nx > n || n <= 0 || ny > n) continue;
					if (board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
					dist[nx][ny] = dist[x][y] + 1;
					nxt.push({ nx, ny });
				}
			}
			if (target.size() > 0) break;
			if (nxt.size() == 0) {
				cout << -1;
				return 0;
			}
			Q = nxt;
		}
		
		sort(target.begin(), target.end());
		pair<int, int> src = { target[0].first, target[0].second };
		int src_num = st[src.first][src.second];
		int taxitosrc = dist[src.first][src.second];

		for (int i = 1; i <= n; i++) {
			fill(dist[i] + 1, dist[i] + n + 1, -1);
		}

		Q.push({ src.first, src.second });
		dist[src.first][src.second] = 0;
		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (board[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[x][y] + 1;
				Q.push({ nx, ny });
			}
		}

		int srctodest = dist[passenger[src_num][1].first][passenger[src_num][1].second];

		if (taxitosrc + srctodest > k || dist[passenger[src_num][1].first][passenger[src_num][1].second] == -1) {
			cout << -1;
			return 0;
		}
		
		k = k - (taxitosrc + srctodest) + srctodest * 2;
		cnt--;
		taxi = { passenger[src_num][1].first, passenger[src_num][1].second };
		st[passenger[src_num][0].first][passenger[src_num][0].second] = 0;
		en[passenger[src_num][1].first][passenger[src_num][1].second] = 0;
	}

	cout << k;
}