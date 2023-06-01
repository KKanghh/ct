#include <bits/stdc++.h>
using namespace std;
char board[50][50];
int dist[50][50];
int adj[251][251];
pair<int, int> S[251];
int key;
int num[50][50];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

bool vis[251];

queue<pair<int, int>> Q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, -1);
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				Q.push({ i, j });
				dist[i][j] = 0;
				num[i][j] = 0;
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

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == '1' || dist[nx][ny] >= 0) continue;
			
			dist[nx][ny] = dist[x][y] + 1;
			if (board[nx][ny] == 'K') {
				key++;
				S[key] = { nx, ny };
				num[nx][ny] = key;
				adj[0][key] = dist[nx][ny];
			}
			Q.push({ nx, ny });
		}
	}

	if (key != m) {
		cout << -1;
		return 0;
	}
	
	for (int i = 1; i <= key; i++) {
		for (int j = 0; j < n; j++) fill(dist[j], dist[j] + n, -1);
		dist[S[i].first][S[i].second] = 0;
		Q.push({S[i].first, S[i].second});

		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] == '1' || dist[nx][ny] >= 0) continue;


				dist[nx][ny] = dist[x][y] + 1;
				if (board[nx][ny] == 'S' || board[nx][ny] == 'K') {
					adj[i][num[nx][ny]] = dist[nx][ny];
				}
				Q.push({ nx, ny });
			}
		}
	}

	int cnt = 0;
	long long len = 0;

	vis[0] = true;
	for (int i = 1; i <= key; i++) {
		pq.push({ adj[0][i], i });
	}

	while (cnt < key) {
		int b, d;
		tie(d, b) = pq.top();
		pq.pop();
		if (vis[b]) continue;

		cnt++;
		vis[b] = true;
		len += d;
		for (int i = 0; i <= key; i++) {
            if (!vis[i]) pq.push({ adj[b][i], i });
        }

	}

	cout << len;
}