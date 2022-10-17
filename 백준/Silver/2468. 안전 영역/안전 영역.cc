#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
bool vis[100][100];
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, high = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (high < board[i][j]) high = board[i][j];
		}
	}
	int safe_area = 1;
	for (int rain = 1; rain < high; rain++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] > rain && !vis[i][j]) {
					cnt++;
					vis[i][j] = true;
					Q.push({ i, j });

					while (!Q.empty()) {
						auto t = Q.front();
						Q.pop();
						for (int k = 0; k < 4; k++) {
							int nx = t.X + dx[k];
							int ny = t.Y + dy[k];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							if (board[nx][ny] <= rain || vis[nx][ny]) continue;
							vis[nx][ny] = true;
							Q.push({ nx, ny });
						}

					}
				}
			}
		}
		if (cnt > safe_area) safe_area = cnt;
		
		for (int i = 0; i < N; i++) {
			fill(vis[i], vis[i] + N, false);
		}
	}

	cout << safe_area;
}