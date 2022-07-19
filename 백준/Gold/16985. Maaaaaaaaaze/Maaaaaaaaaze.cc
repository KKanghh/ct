#include <bits/stdc++.h>
using namespace std;
int maze[5][5][5], dist[5][5][5], now_maze[5][5][5];
queue<tuple<int, int, int>> Q;
int dz[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int MIN = 12600;

void spin(int num, int times) {
	int tmp[5][5];
	for (int i = 0; i < times; i++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				tmp[x][y] = now_maze[num][5 - 1 - y][x];
			}
		}
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				now_maze[num][x][y] = tmp[x][y];
			}
		}
	}
}

int main() {
	int kang = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int z = 0; z < 5; z++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cin >> maze[z][x][y];
			}
		}
	}
	int a[5] = { 0, 1, 2, 3, 4 };
	int cnt = 1;
	for (int i = 0; i < 5; i++) cnt *= 4;
	do {
		for (int k = 0; k < cnt; k++) {
			kang++;
			for (int i = 0; i < 5; i++) {
				for (int x = 0; x < 5; x++) {
					for (int y = 0; y < 5; y++) {
						now_maze[i][x][y] = maze[a[i]][x][y];
					}
				}
				for (int j = 0; j < 5; j++) {
					fill(dist[i][j], dist[i][j] + 5, -1);
				}
			}
			int tmp = k;
			for (int j = 0; j < 5; j++) {
				spin(j, tmp % 4);
				tmp /= 4;
			}
			if (now_maze[0][0][0] == 0) continue;
			Q.push({ 0, 0, 0 });
			dist[0][0][0] = 0;
			while (!Q.empty()) {
				int x, y, z;
				tie(z, x, y) = Q.front();
				Q.pop();
				for (int dir = 0; dir < 6; dir++) {
					int nz = z + dz[dir];
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
					if (now_maze[nz][nx][ny] == 0 || dist[nz][nx][ny] >= 0) continue;
					dist[nz][nx][ny] = dist[z][x][y] + 1;
					Q.push({ nz, nx, ny });
				}
			}
			if (dist[4][4][4] == -1) continue;
			MIN = min(MIN, dist[4][4][4]);
		}
	} while (next_permutation(a, a + 5));
	if (MIN == 12600) MIN = -1;
	cout << MIN;
}