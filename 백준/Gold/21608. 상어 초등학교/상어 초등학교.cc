#include <bits/stdc++.h>
using namespace std;
int board[21][21];
int n, ans;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
set<int> S[401];
vector<int> order;
int comfort[5] = { 0, 1, 10, 100, 1000 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n * n; i++) {
		int k, t;
		cin >> k;
		order.push_back(k);
		for (int j = 0; j < 4; j++) {
			cin >> t;
			S[k].insert(t);
		}
	}

	for (int i = 0; i < n * n; i++) {
		tuple<int, int, int, int> mn = { 4, 4, n, n };
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				if (board[x][y] > 0) continue;
				int fr = 4;
				int em = 4;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
					if (board[nx][ny] == 0) em--;
					if (S[order[i]].count(board[nx][ny])) fr--;
				}
				mn = min(mn, { fr, em, x, y });
			}
		}

		int fr, em, x, y;
		tie(fr, em, x, y) = mn;
		board[x][y] = order[i];
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
				if (S[board[x][y]].count(board[nx][ny])) cnt++;
			}

			ans += comfort[cnt];
		}
	}

	cout << ans;
}