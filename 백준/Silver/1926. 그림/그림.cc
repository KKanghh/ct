#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[500][500];
bool vis[500][500];
int max_area, cnt;
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int h, w;

void BFS(int x, int y) {
	int area = 0;
	vis[x][y] = true;
	area++;
	Q.push({ x, y });
	while (!Q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = Q.front().X + dx[i];
			int ny = Q.front().Y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny] == 0 || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			Q.push({ nx, ny });
			area++;
		}
		Q.pop();
	}

	if (max_area < area) max_area = area;
}

int main() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << max_area;

}