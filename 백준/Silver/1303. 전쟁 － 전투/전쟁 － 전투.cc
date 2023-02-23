#include <bits/stdc++.h>
using namespace std;
char board[100][100];
bool vis[100][100];
int mine, yours;
queue<pair<int, int>> Q;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0 ,-1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			int team = 1;
			vis[i][j] = true;
			Q.push({ i, j });
			while (!Q.empty()) {
				int x, y;
				tie(x, y) = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[x][y] != board[nx][ny]) continue;

					vis[nx][ny] = true;
					Q.push({ nx, ny });
					team++;
				}
			}
			if (board[i][j] == 'W') mine += team * team;
			else yours += team * team;
		}
	}

	cout << mine << ' ' << yours;
}