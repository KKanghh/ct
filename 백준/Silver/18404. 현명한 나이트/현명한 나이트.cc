#include <bits/stdc++.h>
using namespace std;
int dist[501][501];
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
vector<pair<int, int>> V;
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 1; i++) fill(dist[i], dist[i] + n + 1, -1);

	int x, y;
	cin >> x >> y;
	dist[x][y] = 0;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		V.push_back({a, b});
	}

	Q.push({x, y});
	while (!Q.empty()) {
		int tx, ty;
		tie(tx, ty) = Q.front();
		Q.pop();

		for (int dir = 0; dir < 8; dir++) {
			int nx = tx + dx[dir];
			int ny = ty + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
			if (dist[nx][ny] >= 0) continue;

			dist[nx][ny] = dist[tx][ty] + 1;
			Q.push({nx, ny});
		}
	}

	for (int i = 0 ; i < m; i++) cout << dist[V[i].first][V[i].second] << ' ';
}