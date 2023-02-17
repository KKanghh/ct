#include <bits/stdc++.h>
using namespace std;

int board[3000][3000], dist[3000][3000];
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
			if (board[i][j] == 2) {
				dist[i][j] = 0;
				Q.push({ i, j });
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
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] == 1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			if (board[nx][ny] >= 3) {
				cout << "TAK\n" << dist[nx][ny];
				return 0;
			}
			Q.push({ nx, ny });
		}
	}

	cout << "NIE";
}