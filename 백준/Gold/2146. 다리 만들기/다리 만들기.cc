#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
int dist[100][100];
queue<pair<int, int>> q;
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) Q.push({ i, j });
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && dist[i][j] == 0) {
				cnt++;
				dist[i][j] = 1;
				q.push({ i, j });
				while (!q.empty()) {
					auto a = q.front();
					q.pop();
					board[a.X][a.Y] = cnt;
					for (int k = 0; k < 4; k++) {
						int nx = a.X + dx[k];
						int ny = a.Y + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (dist[nx][ny] > 0 || board[nx][ny] == 0) continue;
						dist[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
	int ans = 1000;
	while (!Q.empty()) {
		auto a = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a.X + dx[i];
			int ny = a.Y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (board[nx][ny] == board[a.X][a.Y]) continue;
			if (board[nx][ny] == 0) {
				board[nx][ny] = board[a.X][a.Y];
				dist[nx][ny] = dist[a.X][a.Y] + 1;
				Q.push({ nx, ny });
				continue;
			}
			ans = min(dist[nx][ny] + dist[a.X][a.Y] - 2, ans);
		}
	}

	cout << ans;
}