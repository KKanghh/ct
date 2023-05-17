#include <bits/stdc++.h>
using namespace std;
int A[101], B[101], board[101][101], D[205][101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;

	cin >> n >> m >> a >> b;

	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> x >> y;

		A[x] = max(A[x], y);
		B[y] = max(B[y], x);
		board[x][y] = 1;
	}

	for (int i = 0; i < b; i++) {
		int x, y;
		cin >> x >> y;

		board[x][y] = 2;
	}

	D[0][0][1] = 1;

	for (int k = 0; k <= a; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == 2) continue;
				if (board[i][j] == 0) D[k][i][j] = D[k][i - 1][j] + D[k][i][j - 1];
				else D[k + 1][i][j] = D[k][i - 1][j] + D[k][i][j - 1];
			}
		}
	}
	

	
	cout << D[a][n][m];
}