#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int dist[100][100];
deque<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		fill(dist[i], dist[i] + m, -1);
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j] - '0';
		}
	}

	dist[0][0] = 0;
	Q.push_back({ 0, 0 });

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop_front();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] <= dist[x][y] + 1 && dist[nx][ny] > -1) continue;
			dist[nx][ny] = dist[x][y] + board[nx][ny];
			if (board[nx][ny] == 0) Q.push_front({ nx, ny });
			else Q.push_back({ nx, ny });
		}
	}

	cout << dist[n - 1][m - 1];
}