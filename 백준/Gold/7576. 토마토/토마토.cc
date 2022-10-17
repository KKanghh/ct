#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1000][1000];
int vis[1000][1000];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) vis[i][j] = -1;
			else if (board[i][j] == 1) {
				vis[i][j] = 1;
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = Q.front().X + dx[i];
			int ny = Q.front().Y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] != 0) continue;
			if (vis[nx][ny] > 0 && vis[nx][ny] <= vis[Q.front().X][Q.front().Y] + 1) continue;
			vis[nx][ny] = vis[Q.front().X][Q.front().Y] + 1;
			Q.push({ nx, ny });
		}
		Q.pop();
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else {
				if (max < vis[i][j]) max = vis[i][j];
			}
		}
	}

	cout << max - 1;
}