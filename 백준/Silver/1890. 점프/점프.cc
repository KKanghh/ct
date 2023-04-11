#include <bits/stdc++.h>
using namespace std;
int board[111][111];
long long D[111][111];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}


	D[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (D[i][j] == 0 || board[i][j] == 0) continue;
			D[i + board[i][j]][j] += D[i][j];
			D[i][j + board[i][j]] += D[i][j];
		}
	}

	cout << D[n][n];
}