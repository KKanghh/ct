#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100][100];
int dist[100][100][100];
queue<pair<int, pair<int, int>>> Q;
int dx[6] = { 0, 0, 1, 0, -1, 0 };
int dy[6] = { 0, 0, 0, -1, 0, 1 };
int dz[6] = { 1, -1, 0, 0, 0 ,0 };

int main() {
	int N, M, H;
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == -1) dist[i][j][k] = -1;
				else if (board[i][j][k] == 1) {
					dist[i][j][k] = 1;
					// 높이, 행 ,렬
					Q.push({ i,{ j, k } });
				}
			}
		}
	}

	while (!Q.empty()) {
		for (int i = 0; i < 6; i++) {
			int nz = Q.front().X + dz[i];
			int nx = Q.front().Y.X + dx[i];
			int ny = Q.front().Y.Y + dy[i];
			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nz][nx][ny] != 0) continue;
			dist[nz][nx][ny] = dist[Q.front().X][Q.front().Y.X][Q.front().Y.Y] + 1;
			Q.push({ nz, { nx, ny } });
		}

		Q.pop();

	}


	int max = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (dist[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				else if (dist[i][j][k] > max) max = dist[i][j][k];
			}
		}
	}

	cout << max - 1;
}