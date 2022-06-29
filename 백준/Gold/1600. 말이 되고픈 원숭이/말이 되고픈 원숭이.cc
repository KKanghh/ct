#include <bits/stdc++.h>
using namespace std;
int board[200][200];
int dist[31][200][200];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int hx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int hy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

queue<tuple<int, int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, W, H;

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}
	Q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;

	int horse, x, y;
	while (!Q.empty()) {
		tie(horse, x, y) = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == 1 || dist[horse][nx][ny] > 0) continue;
			Q.push({ horse, nx, ny });
			dist[horse][nx][ny] = dist[horse][x][y] + 1;
		}
		if (horse >= K) continue;
		for (int i = 0; i < 8; i++) {
			int nx = x + hx[i];
			int ny = y + hy[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == 1 || dist[horse + 1][nx][ny] > 0) continue;
			Q.push({ horse + 1, nx, ny });
			//dist[horse + 1][x][y] = dist[horse][x][y];
			dist[horse + 1][nx][ny] = dist[horse][x][y] + 1;
		}
	}

	int min = 99999999;
	for (int i = K; i >= 0; i--) {
		if (dist[i][H - 1][W - 1] > 0) {
			if (min > dist[i][H - 1][W - 1]) min = dist[i][H - 1][W - 1];
		}
	}

	if (min == 99999999) cout << -1;
	else cout << min - 1;

	/*for (int i = K; i >= 0; i--) {
		if (dist[i][H - 1][W - 1] > 0) {
			cout << dist[i][H - 1][W - 1] - 1;
			return 0;
		}
	}

	cout << -1;*/
}