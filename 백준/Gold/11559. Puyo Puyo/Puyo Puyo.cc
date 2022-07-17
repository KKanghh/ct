#include <bits/stdc++.h>
using namespace std;

char board[12][6];
bool visited[12][6];
queue<pair<int, int>> Q;
int combo;
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool find() {
	bool is4 = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] != '.' && !visited[i][j]) {
				vector<pair<int, int>> V;
				visited[i][j] = true;
				Q.push({ i, j });
				while (!Q.empty()) {
					int x, y;
					tie(x, y) = Q.front();
					Q.pop();
					V.push_back({ x, y });
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
						if (board[x][y] != board[nx][ny] || visited[nx][ny]) continue;
						visited[nx][ny] = true;
						Q.push({ nx, ny });
					}
				}
				
				if (V.size() >= 4) {
					is4 = true;
					for (auto e : V) {
						int x, y;
						tie(x, y) = e;
						board[x][y] = ' ';
					}
				}
			}
		}
	}
	return is4;
}

void clean() {
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 12; i++) {
			if (board[i][j] == ' ') {
				int x = i;
				while (x > 0) {
					board[x][j] = board[x - 1][j];
					x--;
				}
				board[0][j] = '.';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		if (!find()) {
			break;
		}
		combo++;
		clean();
		for (int i = 0; i < 12; i++) {
			fill(visited[i], visited[i] + 6, false);
		}
	}

	cout << combo;
}