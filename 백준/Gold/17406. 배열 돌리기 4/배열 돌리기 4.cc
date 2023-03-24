#include <bits/stdc++.h>
using namespace std;
int board[51][51];
int n, m, k, mn = 0x3f3f3f3f;
vector<tuple<int, int, int>> rotation;
vector<int> cases;

void func(int board[51][51], int r, int c, int s) {
	for (; s > 0; s--) {
		int x = r - s;
		int y = c - s;
		int temp = board[x][y];
		while (x < r + s) {
			board[x][y] = board[x + 1][y];
			x++;
		}
		while (y < c + s) {
			board[x][y] = board[x][y + 1];
			y++;
		}
		while (x > r - s) {
			board[x][y] = board[x - 1][y];
			x--;
		}
		while (y > c - s) {
			board[x][y] = board[x][y - 1];
			y--;
		}

		board[r - s][c - s + 1] = temp;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cases.push_back(i);
		int r, c, s;
		cin >> r >> c >> s;
		rotation.push_back({ r, c, s });
	}

	do {
		int temp_board[51][51] = {0};
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp_board[i][j] = board[i][j];
			}
		}

		for (int e : cases) {
			int r, c, s;
			tie(r, c, s) = rotation[e];
			func(temp_board, r, c, s);
		}

		int val = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++) {
			int row = 0;
			for (int j = 1; j <= m; j++) {
				row += temp_board[i][j];
			}
			val = min(val, row);
		}
		mn = min(mn, val);
	} while (next_permutation(cases.begin(), cases.end()));

	cout << mn;
}