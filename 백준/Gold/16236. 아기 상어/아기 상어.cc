#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[20][20], dist[20][20];
int shark_size = 2;
int N, x, y, tik, eat;
queue<pair<int, int>> Q;
vector<pair<int, int>> V;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}

	while (true) {
		for (int i = 0; i < N; i++) fill(dist[i], dist[i] + N, -1);
		queue<pair<int, int>> tQ;
		vector<pair<int, int>> edible;
		bool find = false;
		dist[x][y] = 0;
		tQ.push({ x, y });
		while (!tQ.empty()) {
			while (!tQ.empty()) {
				Q.push(tQ.front());
				tQ.pop();
			}
			
			while (!Q.empty()) {
				int gx, gy;
				tie(gx, gy) = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = gx + dx[dir];
					int ny = gy + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (board[nx][ny] > shark_size || dist[nx][ny] >= 0) continue;
					if (board[nx][ny] == shark_size || board[nx][ny] == 0) {
						dist[nx][ny] = dist[gx][gy] + 1;
						tQ.push({ nx, ny });
						continue;
					}
					edible.push_back({ nx, ny });
					dist[nx][ny] = dist[gx][gy] + 1;
				}
			}

			if (edible.size() > 0) {
				sort(edible.begin(), edible.end());
				board[x][y] = 0;
				x = edible[0].X;
				y = edible[0].Y;
				eat++;
				if (eat == shark_size) {
					eat = 0;
					shark_size++;
				}
				board[x][y] = 9;
				tik += dist[edible[0].X][edible[0].Y];
				while (!edible.empty()) edible.pop_back();
				while (!tQ.empty()) tQ.pop();
				find = true;
				break;
			}
		}

		if (!find) {
			break;
		}
	}

	cout << tik;
}