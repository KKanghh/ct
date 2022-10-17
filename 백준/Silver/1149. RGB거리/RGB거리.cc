#include <bits/stdc++.h>
using namespace std;
int board[3][1001], price[3][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> price[0][i] >> price[1][i] >> price[2][i];
	}

	board[0][1] = price[0][1];
	board[1][1] = price[1][1];
	board[2][1] = price[2][1];

	for (int i = 2; i <= n; i++) {
		board[0][i] = min(board[1][i - 1], board[2][i - 1]) + price[0][i];
		board[1][i] = min(board[0][i - 1], board[2][i - 1]) + price[1][i];
		board[2][i] = min(board[0][i - 1], board[1][i - 1]) + price[2][i];
	}
	int ans = min(board[0][n], board[1][n]);
	cout << min(ans, board[2][n]);
}