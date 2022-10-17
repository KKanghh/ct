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

	int M, N, K;

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = N - d; j < N - b; j++) {
			for (int k = a; k < c; k++) {
				board[j][k] = 1;
			}
		}

	}
	int cnt = 0;
	vector<int> size;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0 && !vis[i][j]) {
				vis[i][j] = true;
				cnt++;
				int area = 1;
				Q.push({ i, j });
				while (!Q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = Q.front().X + dx[k];
						int ny = Q.front().Y + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] == 1 || vis[nx][ny]) continue;
						vis[nx][ny] = true;
						Q.push({ nx, ny });
						area++;
					}
					Q.pop();
				}
				size.push_back(area);
			}
		}
	}

	cout << cnt << '\n';
	sort(size.begin(), size.end());
	for (auto e : size) cout << e << ' ';
}