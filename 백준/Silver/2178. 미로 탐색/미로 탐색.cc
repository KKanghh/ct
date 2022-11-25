#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int dist[100][100];
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j] - '0';
		}
	}

	Q.push({ 0, 0 });
	dist[0][0] = 1;

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] > 0 || board[nx][ny] == 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			Q.push({ nx, ny });
		}
	}

	cout << dist[n - 1][m - 1];
}