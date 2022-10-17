#include <bits/stdc++.h>
using namespace std;
char building[30][30][30];
int dist[30][30][30];

queue<tuple<int, int, int>> Q;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0 ,0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int L, R, C;

void BFS() {
	while (!Q.empty()) {
		auto a = Q.front();
		Q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = get<0>(a) + dz[i];
			int nx = get<1>(a) + dx[i];
			int ny = get<2>(a) + dy[i];
			if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (building[nz][nx][ny] == '#' || dist[nz][nx][ny] > 0) continue;
			dist[nz][nx][ny] = dist[get<0>(a)][get<1>(a)][get<2>(a)] + 1;
			Q.push(make_tuple(nz, nx, ny));
		}
	}
}

int main() {
	int goal_z, goal_x, goal_y;
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string input;
				cin >> input;
				for (int k = 0; k < C; k++) {
					building[i][j][k] = input[k];
					if (building[i][j][k] == 'S') {
						dist[i][j][k] = 1;
						Q.push(make_tuple(i, j, k));
					}
					if (building[i][j][k] == 'E') {
						goal_z = i;
						goal_x = j;
						goal_y = k;
					}
				}
			}
		}

		BFS();

		if (dist[goal_z][goal_x][goal_y] > 0) {
			cout << "Escaped in " << dist[goal_z][goal_x][goal_y] - 1 << " minute(s).\n";
		}
		else cout << "Trapped!\n";

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				fill(dist[i][j], dist[i][j] + C, 0);
			}
		}
	}
}