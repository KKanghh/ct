#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[8][8], copy_board[8][8];
int N, M, mx = 0;
bool selected[64];
queue<pair <int, int>> Q;

vector<pair<int, int>> virus;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fill(selected, selected + 64, true);
	selected[0] = false;
	selected[1] = false;
	selected[2] = false;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	bool wall = true;
	do {
		wall = true;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				copy_board[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < N * M; i++) {
			if (!selected[i]) {
				int x = i / M;
				int y = i % M;
				if (copy_board[x][y] != 0) {
					wall = false;
					break;
				}
				copy_board[x][y] = 1;
			}
		}

		if (!wall) continue;

		for (auto e : virus) {
			Q.push({ e.X, e.Y });
		}

		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (copy_board[nx][ny] != 0) continue;
				copy_board[nx][ny] = 2;
				Q.push({ nx, ny });
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_board[i][j] == 0) cnt++;
			}
		}
		mx = max(cnt, mx);
	} while (next_permutation(selected, selected + N * M));

	cout << mx;
}