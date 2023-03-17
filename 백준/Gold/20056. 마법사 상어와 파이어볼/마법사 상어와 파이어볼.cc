#include<bits/stdc++.h>
using namespace std;

deque<int> board[50][50];
vector<tuple<pair<int, int>, int, int, int, int>> fireballs;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool set_direction(vector<int> V) {
	int m, s, d, t;
	pair<int, int> place;
	tie(place, m, s, d, t) = fireballs[V[0]];
	int flag = d % 2, siz = V.size();
	for (int i = 1; i < siz; i++) {
		tie(place, m, s, d, t) = fireballs[V[i]];
		if (d % 2 != flag) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	int id = 0;

	for (int i = 0; i < m; i++) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		fireballs.push_back({ {x - 1, y - 1}, m, s, d, 0 });
		board[x - 1][y - 1].push_back(id++);
	}

	int tik = 0;
	while (tik++ < k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int size = board[i][j].size();
				int p = 0;
				while (p++ < size) {
					int cur = board[i][j].front();
					board[i][j].pop_front();
					pair<int, int> lo;
					int x, y, m, s, d, t;
					tie(lo, m, s, d, t) = fireballs[cur];
					if (t == tik) {
						board[i][j].push_back(cur);
						continue;
					}
					tie(x, y) = lo;
					for (int l = 0; l < s; l++) {
						int nx = x + dx[d];
						int ny = y + dy[d];
						if (nx < 0) nx += n;
						if (nx >= n) nx -= n;
						if (ny < 0) ny += n;
						if (ny >= n) ny -= n;
						x = nx;
						y = ny;
					}
					fireballs[cur] = { {x, y}, m, s, d, tik };
					board[x][y].push_back(cur);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j].size() > 1) {
					vector<int> C;
					int M = 0, S = 0;
					while (!board[i][j].empty()) {
						C.push_back(board[i][j].front());
						pair<int, int> lo;
						int m, s, d, t;
						tie(lo, m, s, d, t) = fireballs[board[i][j].front()];
						M += m;
						S += s;
						board[i][j].pop_front();
					}
					bool flag = set_direction(C);
					int size = C.size();
					if (M / 5 == 0) continue;
					for (int k = 0; k < 4; k++) {
						fireballs.push_back({ {i, j}, M / 5, S / size, 2 * k + 1 - flag, tik });
						board[i][j].push_back(id++);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (!board[i][j].empty()) {
				int cur = board[i][j].front();
				board[i][j].pop_front();

				pair<int, int> lo;
				int m, s, d, t;
				tie(lo, m, s, d, t) = fireballs[cur];
				ans += m;
			}
		}
	}
	cout << ans;
}