#include <bits/stdc++.h>
using namespace std;

char board[5][5];
int mx = -0x3f3f3f3f, mn = 0x3f3f3f3f, n;
deque<char> V;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int x, int y) {
	V.push_back(board[x][y]);
	if (x == n - 1 && y == n - 1) {
		int num = 0;
		int oper = '+';
		for (char e : V) {
			if (e - '0' < 0 || e - '0' > 5) {
				oper = e;
			}
			else {
				if (oper == '+') {
					num += e - '0';
				}
				else if (oper == '-') {
					num -= e - '0';
				}
				else num *= e - '0';
			}
		}

		mx = max(mx, num);
		mn = min(mn, num);
		return;
	}

	for (int dir = 0; dir < 2; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		dfs(nx, ny);
		V.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0);

	cout << mx << ' ' << mn;
}