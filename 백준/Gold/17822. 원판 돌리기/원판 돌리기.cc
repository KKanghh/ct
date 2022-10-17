#include <bits/stdc++.h>
using namespace std;
deque<int> board[51];
int n, m, t;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void rotate(int x, int d, int k) {
	if (d == 0) k = m - k;
	for (int i = x; i <= n; i += x) {
		for (int j = 0; j < k; j++) {
			board[i].push_back(board[i].front());
			board[i].pop_front();
		}
	}
	
	queue<pair<int, int>> Q;
	double sm = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			sm += board[i][j];
			cnt++;
			for (int dir = 0; dir < 4; dir++) {
				int ni = i + dx[dir];
				int nj = j + dy[dir];
				if (ni <= 0 || ni > n) continue;
				if (nj == -1) nj = m - 1;
				if (nj == m) nj = 0;

				if (board[i][j] == board[ni][nj]) {
					Q.push({ i, j });
					Q.push({ ni, nj });
				}
			}
		}
	}

	if (Q.empty()) {
		double d = sm / cnt;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] > 0 && board[i][j] < d) board[i][j]++;
				else if (board[i][j] > d) board[i][j]--;
			}
		}
	}

	else {
		while (!Q.empty()) {
			int i, j;
			tie(i, j) = Q.front();
			Q.pop();
			board[i][j] = 0;
		}
	}
}


int main() {
	
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			board[i].push_back(tmp);
		}
	}

	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		rotate(x, d, k);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) ans += board[i][j];
	}

	cout << ans;
}