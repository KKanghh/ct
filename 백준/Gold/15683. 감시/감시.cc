#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[8][8];
int N, M;
vector<pair<int, int>> cctv;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) cnt++;
			else if (board[i][j] < 6) cctv.push_back({ i,j });
		}
	}

	int n = cctv.size(), mn = cnt;
	for (int i = 0; i < pow(4, n); i++) {
		int tmp = i, count = 0;
		bool visit[8][8] = {};
		for (int j = 0; j < n; j++) {
			int a = tmp % 4;
			tmp = tmp / 4;
			int nx = cctv[j].X;
			int ny = cctv[j].Y;
			if (board[nx][ny] == 1) {
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
			}
			else if (board[nx][ny] == 2) {
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 2) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
			}
			else if (board[nx][ny] == 3) {
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 1) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
			}
			else if (board[nx][ny] == 4) {
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 1) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 1) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
			}
			else if (board[nx][ny] == 5) {
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 1) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 1) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
				nx = cctv[j].X;
				ny = cctv[j].Y;
				a = (a + 1) % 4;
				while (true) {
					nx += dx[a];
					ny += dy[a];
					if (board[nx][ny] == 6 || nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (visit[nx][ny] || board[nx][ny] != 0) continue;
					visit[nx][ny] = true;
					count++;
				}
			}
		}
		if (cnt - count < mn) mn = cnt - count;
	}

	cout << mn;
}