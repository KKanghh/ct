#include <bits/stdc++.h>
using namespace std;
int board[50][50], dist[50][50];
bool selected[10];
vector<pair<int, int>> virus;
int N, M;
queue<pair<int, int>> Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(selected, selected + 10, true);
	cin >> N >> M;
	int mn = 0x7fffffff;
	fill(selected, selected + M, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i, j });
		}
	}

	do {
		for (int i = 0; i < N; i++) {
			fill(dist[i], dist[i] + N, -1);
		}
		for (int i = 0; i < virus.size(); i++) {
			if (selected[i] == 0) {
				int x, y;
				tie(x, y) = virus[i];
				dist[x][y] = 0;
				Q.push({ x, y });
			}
		}

		while (!Q.empty()) {
			int x, y;
			tie(x, y) = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (dist[nx][ny] > -1 || board[nx][ny] == 1) continue;
				dist[nx][ny] = dist[x][y] + 1;
				Q.push({ nx, ny });
			}
		}
		int mx = 0;
		bool psbl = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0 && dist[i][j] == -1) psbl = false;
				mx = max(dist[i][j], mx);
			}
		}
		
		if (psbl) {
			mn = min(mx, mn);
		}

	} while (next_permutation(selected, selected + virus.size()));
	if (mn == 0x7fffffff) mn = -1;
	cout << mn;
}