#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool mask[25];
char board[5][5];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int cnt;

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	fill(mask + 7, mask + 25, true);
	do {
		queue<pair<int, int>> Q;
		bool vis[5][5] = {};
		int adj = 0, dasom = 0;
		for (int i = 0; i < 25; i++) {
			if (!mask[i]) {
				if (Q.empty()) {
					Q.push({ i / 5, i % 5 });
					vis[i / 5][i % 5] = true;
				}
			}
		}
		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();
			adj++;
			if (board[x][y] == 'S') dasom++;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (vis[nx][ny] || mask[nx * 5 + ny]) continue;
				vis[nx][ny] = true;
				Q.push({ nx, ny });
			}
		}

		if (adj == 7 && dasom >= 4) cnt++;
	} while (next_permutation(mask, mask + 25));
	cout << cnt;;
}