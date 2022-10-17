#include <bits/stdc++.h>
using namespace std;
char board[20][20];
int vis[20][20];
int selected[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> Q;

int main() {
	while (true) {
		int mn = 0x7fffffff;
		vector<pair<int, int>> V;
		int w, h, dist[11][11] = {};
		bool impossible = false;
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			fill(board[i], board[i] + w, '.');
			fill(vis[i], vis[i] + w, -1);
		}
		int togo = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'o') {
					Q.push({ i,j });
					vis[i][j] = 0;
				}
				if (board[i][j] == '*') {
					board[i][j] = togo++ + '0';
					V.push_back({ i, j });
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
				if (nx < 0 || nx >= h || ny < 0 || ny > w) continue;
				if (vis[nx][ny] >= 0 || board[nx][ny] == 'x') continue;
				vis[nx][ny] = vis[x][y] + 1;
				Q.push({ nx, ny });
				if (board[nx][ny] - '0' >= 0 && board[nx][ny] - '0' <= 9) {
					int num = board[nx][ny] - '0' + 1;
					dist[0][num] = vis[nx][ny];
					dist[num][0] = vis[nx][ny];
				}
			}
		}

		for (int i = 1; i <= togo; i++) {
			if (dist[0][i] == 0) impossible = true;
		}

		if (impossible) {
			cout << -1 << '\n';
			continue;
		}

		for (int i = 0; i < togo; i++) {
			for (int k = 0; k < h; k++) {
				fill(vis[k], vis[k] + w, -1);
			}
			int x, y; 
			tie(x, y) = V[i];
			vis[x][y] = 0;
			Q.push({ x, y });
			while (!Q.empty()) {
				int x, y;
				tie(x, y) = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
					if (vis[nx][ny] >= 0 || board[nx][ny] == 'x') continue;
					vis[nx][ny] = vis[x][y] + 1;
					Q.push({ nx, ny });
					if (board[nx][ny] - '0' >= 0 && board[nx][ny] - '0' <= 9) {
						int num = board[nx][ny] - '0' + 1;
						dist[i + 1][num] = vis[nx][ny];
						dist[num][i + 1] = vis[nx][ny];
					}
				}
			}
		}

		do {
			int prev = 0, d = 0;
			for (int i = 0; i < togo; i++) {
				d += dist[prev][selected[i]];
				prev = selected[i];
			}
			mn = min(d, mn);
		} while (next_permutation(selected, selected + togo));
		cout << mn << '\n';
	}
}