#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[300][300];
int melt[300][300];
bool vis[300][300];
bool isMelt[300][300];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> Q;
int N, M;

void BFS(int a, int b) {
	Q.push({ a, b });
	vis[a][b] = true;
	while (!Q.empty()) {
		auto a = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a.X + dx[i];
			int ny = a.Y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 0 || vis[nx][ny]) continue;
			Q.push({ nx, ny });
			vis[nx][ny] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					melt[nx][ny]++;
				}
			}
		}
	}


	int cnt = 1, year = -1;
	while (cnt == 1) {
		cnt = 0;
		year++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] > 0 && !vis[i][j]) {
					BFS(i, j);
					cnt++;
				}
				if (board[i][j] > 0) {
					board[i][j] -= melt[i][j];
					if (board[i][j] <= 0) {
						board[i][j] = 0;
						isMelt[i][j] = true;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			fill(vis[i], vis[i] + M, false);
			for (int j = 0; j < M; j++) {
				if (isMelt[i][j]) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						melt[nx][ny]++;
					}
					isMelt[i][j] = false;
				}
			}
		}
		/*cout << '\n';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n' << cnt;
		cout << '\n';*/
	}
	

	if (cnt > 1) cout << year;
	else cout << -0;

}