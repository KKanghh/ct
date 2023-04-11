#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
int D[1001][1001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] != 0) D[i][j] = 0;
			else {
				if (board[i - 1][j - 1] == 0 && board[i - 1][j] == 0 && board[i][j - 1] == 0) {
					D[i][j] = min({ D[i - 1][j - 1], D[i][j - 1], D[i - 1][j]}) + 1;
				}
				else {
					D[i][j] = 1;
				}
			}
		}
	}

	int mx = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mx = max(mx, D[i][j]);
		}
	}

	cout << mx;
}