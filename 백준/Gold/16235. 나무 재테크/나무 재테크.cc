#include <bits/stdc++.h>
using namespace std;
int A[11][11], death[11][11], Y[11][11];
deque<int> tree[11][11];
int N, M, K, cnt;
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void spring() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int i = 0; i < tree[x][y].size(); i++) {
				if (Y[x][y] >= tree[x][y][i]) {
					Y[x][y] -= tree[x][y][i];
					tree[x][y][i]++;
				}
				else {
					while (tree[x][y].size() > i) {
						Y[x][y] += tree[x][y].back() / 2;
						tree[x][y].pop_back();
					}
					break;
				}
			}
		}
	}
}

void fall() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int e : tree[x][y]) {
				if (e % 5) continue;
				for (int dir = 0; dir < 8; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
					tree[nx][ny].push_front(1);
				}
				
			}
		}
	}
}
void winter() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			Y[x][y] += A[x][y];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 10; i++) {
		fill(Y[i] + 1, Y[i] + 11, 5);
	}

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	while (M--) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x][y].push_back(age);
		sort(tree[x][y].begin(), tree[x][y].end());
	}

	while (K--) {
		spring();
		fall();
		winter();
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cnt += tree[x][y].size();
		}
	}

	cout << cnt;
}