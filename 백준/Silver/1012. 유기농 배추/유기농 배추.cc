#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int bat[50][50];
bool vis[50][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int test;
	cin >> test;
	while (test--) {
		queue<pair<int, int>> Q;
		int N, M, bch, cnt = 0;
		cin >> M >> N >> bch;
		for (int i = 0; i < N; i++) {
			fill(bat[i], bat[i] + M, 0);
			fill(vis[i], vis[i] + M, false);
		}
		while (bch--) {
			int x, y;
			cin >> y >> x;
			bat[x][y] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bat[i][j] == 1 && !vis[i][j]) {
					Q.push({ i, j });
					vis[i][j] = true;
					cnt++;
					while (!Q.empty()) {
						for (int k = 0; k < 4; k++) {
							int nx = Q.front().X + dx[k];
							int ny = Q.front().Y + dy[k];
							if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
							if (bat[nx][ny] == 0 || vis[nx][ny] == true) continue;
							vis[nx][ny] = true;
							Q.push({ nx, ny });
						}
						Q.pop();
					}
				}
			}
		}

		cout << cnt << '\n';
	}
	
}