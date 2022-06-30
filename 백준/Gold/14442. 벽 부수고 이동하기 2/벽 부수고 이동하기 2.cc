#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
int dist[11][1000][1000];
queue<tuple<int, int ,int>> Q;

int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j] - '0';
		}
	}

	dist[0][0][0] = 1;
	Q.push({ 0, 0, 0 });

	int brk, x, y;
	while (!Q.empty()) {
		tie(brk, x, y) = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[brk][nx][ny] > 0) continue;
			if (board[nx][ny] == 1) {
				if (brk == K) continue;
				if (dist[brk + 1][nx][ny] > 0) continue;
				dist[brk + 1][nx][ny] = dist[brk][x][y] + 1;
				Q.push({ brk + 1, nx, ny });
				continue;
			}
			dist[brk][nx][ny] = dist[brk][x][y] + 1;
			Q.push({ brk, nx, ny });
		}
	}

	int L = 0x7fffffff;
	for (int i = 0; i <= K; i++) {
		if (dist[i][N - 1][M - 1] < L && dist[i][N - 1][M - 1] > 0) L = dist[i][N - 1][M - 1];
	}

	if (L == 0x7fffffff) cout << -1;
	else cout << L;
}