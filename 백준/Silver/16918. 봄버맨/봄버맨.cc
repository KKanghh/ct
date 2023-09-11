#include <bits/stdc++.h>
using namespace std;
int board[200][200];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q[201];
queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, n;
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++) {
		fill(board[i], board[i] + c, -2);
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'O') {
				board[i][j] = 0;
				Q[0].push({i, j});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			while(i >= 3 && !Q[i - 3].empty()) {
				int x, y;
				tie(x, y) = Q[i - 3].front();
				Q[i - 3].pop();
				if (board[x][y] != (i - 3)) continue;
				pq.push({x, y});
			}
			while(!pq.empty()) {
				int x, y;
				tie(x, y) = pq.front();
				pq.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					board[nx][ny] = 0;
				}
			}
		}
		else {
			for (int x = 0; x < r; x++) {
				for (int y = 0; y < c; y++) {
					if (board[x][y] < i - 3) {
						board[x][y] = i;
						Q[i].push({x, y});
					}
				}
			}
		}
	}

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			// cout << board[x][y] << ' ';
			if (board[x][y] > n - 3) cout << 'O';
			else cout << '.';
		}
		cout << '\n';
	}
}