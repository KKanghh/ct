#include <bits/stdc++.h>
using namespace std;
int board[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				board[i][j] += board[i - 1][1];
				continue;
			}
			if (j == i) {
				board[i][j] += board[i - 1][j - 1];
				continue;
			}
			board[i][j] += max(board[i - 1][j - 1], board[i - 1][j]);
		}
	}
	int mx = board[n][1];
	for (int i = 2; i <= n; i++) mx = max(mx, board[n][i]);
	cout << mx;
}