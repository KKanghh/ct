#include <bits/stdc++.h>
using namespace std;
char board[50][50];
bool garbage[50][50];
pair<int, int> dist[50][50];
priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, fx, fy;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j].first = 0x3f3f3f3f;
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				dist[i][j].first = 0;
				pq.push({0, 0, i, j});
			}
			if (board[i][j] == 'F') {
				fx = i;
				fy = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'g') {
				for (int dir = 0; dir < 4; dir++) {
					int ni = i + dx[dir];
					int nj = j + dy[dir];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (board[ni][nj] == 'g' || board[ni][nj] == 'F') continue;
					garbage[ni][nj] = true;
				}
			}
		}
	}

	while (!pq.empty()) {
		int a, b, x, y;
		tie(a, b, x, y) = pq.top();
		pq.pop();
		if (make_pair(a, b) > dist[x][y]) continue;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (make_pair(a + (board[nx][ny] == 'g'), b + garbage[nx][ny]) >= dist[nx][ny]) continue;
			dist[nx][ny] = {a + (board[nx][ny] == 'g'), b + garbage[nx][ny]};
			pq.push({dist[nx][ny].first, dist[nx][ny].second, nx, ny});
		}

	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << dist[i][j].first << ',' << dist[i][j].second << ' ';
	// 	}
	// 	cout << '\n';
	// }

	cout << dist[fx][fy].first << ' ' << dist[fx][fy].second;
}