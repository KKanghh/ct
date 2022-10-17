#include <bits/stdc++.h>
using namespace std;
bool board[101][101];
int cnt;

void draw(int& x, int& y, int d) {
	if (d == 0) {
		board[x][++y] = true;
	}
	else if (d == 1) {
		board[--x][y] = true;
	}
	else if (d == 2) {
		board[x][--y] = true;
	}
	else {
		board[++x][y] = true;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		deque<int> dir;
		board[x][y] = true;
		draw(x, y, d);
		dir.push_back((d + 1) % 4);
		for (int i = 0; i < g; i++) {
			for (int k : dir) {
				draw(x, y, k);
				dir.push_front((k + 1) % 4);
			}
		}

	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) cnt++;
		}
	}

	cout << cnt;
}
