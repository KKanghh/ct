#include <bits/stdc++.h>
using namespace std;
int board[1000001][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	board[1][0] = 0;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int mn = board[i - 1][0], k = i - 1;
		if (i % 2 == 0 && board[i / 2][0] < mn) {
			mn = board[i / 2][0];
			k = i / 2;
		}
		if (i % 3 == 0 && board[i / 3][0] < mn) {
			mn = board[i / 3][0];
			k = i / 3;
		}
		board[i][0] = mn + 1;
		board[i][1] = k;
	}

	cout << board[n][0] << '\n';
	while (n != 0) {
		cout << n << ' ';
		n = board[n][1];
	}
}