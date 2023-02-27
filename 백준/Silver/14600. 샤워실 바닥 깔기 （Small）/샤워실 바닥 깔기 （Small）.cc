#include<bits/stdc++.h>
using namespace std;

int board[5][5];
int cnt = 1;

void tile(int x, int y, int n) {
	if (n == 2) {
		if (x % 2 == 1 && y % 2 == 1) {
			board[x + 1][y + 1] = cnt;
			board[x][y + 1] = cnt;
			board[x + 1][y] = cnt;
		}
		else if (x % 2 == 1 && y % 2 == 0) {
			board[x][y - 1] = cnt;
			board[x + 1][y - 1] = cnt;
			board[x + 1][y] = cnt;
		}
		else if (x % 2 == 0 && y % 2 == 1) {
			board[x - 1][y] = cnt;
			board[x - 1][y + 1] = cnt;
			board[x][y + 1] = cnt;
		}
		else {
			board[x - 1][y - 1] = cnt;
			board[x - 1][y] = cnt;
			board[x][y - 1] = cnt;
		}

		cnt++;
		return;
	}

	int nx = (x - 1) % n + 1 , ny = (y- 1) % n + 1 ;
	int hx = (x - 1) / n * n, hy = (y - 1) / n * n;
	if (nx <= n / 2 && ny <= n / 2) {
		tile(x, y, n / 2);
		tile(n / 2 + hx , n / 2 + hy + 1 , n / 2);
		tile(n / 2 + hx + 1, n / 2 + hy, n / 2);
		tile(n / 2 + hx + 1, n / 2 + hy + 1, n / 2);
		board[n / 2 + hx][n / 2 + hy + 1] = cnt;
		board[n / 2 + hx + 1][n / 2 + hy] = cnt;
		board[n / 2 + hx + 1][n / 2 + hy + 1] = cnt;
	}
	else if (nx <= n / 2 && ny > n / 2) {
		tile(x, y, n / 2);
		tile(n / 2 + hx, n / 2 + hy, n / 2);
		tile(n / 2 + hx + 1, n / 2 + hy, n / 2);
		tile(n / 2 + hx + 1, n / 2 + hy + 1, n / 2);
		board[n / 2 + hx][n / 2 + hy] = cnt;
		board[n / 2 + hx + 1][n / 2 + hy] = cnt;
		board[n / 2 + hx + 1][n / 2 + hy + 1] = cnt;
	}
	else if (nx > n / 2 && ny <= n / 2) {
		tile(x, y, n / 2);
		tile(n / 2 + hx, n / 2 + hy, n / 2);
		tile(n / 2 + hx, n / 2 + hy + 1, n / 2);
		tile(n / 2 + hx + 1, n / 2 + hy + 1, n / 2);
		board[n / 2 + hx][n / 2 + hy] = cnt;
		board[n / 2 + hx][n / 2 + hy + 1] = cnt;
		board[n / 2 + hx + 1][n / 2 + hy + 1] = cnt;
	}
	else {
		tile(x, y, n / 2);
		tile(n / 2 + hx, n / 2 + hy, n / 2);
		tile(n / 2 + hx, n / 2 + hy + 1, n / 2);
		tile(n / 2 + hx + 1, n / 2 + hy, n / 2);
		board[n / 2 + hx][n / 2 + hy] = cnt;
		board[n / 2 + hx + 1][n / 2 + hy] = cnt;
		board[n / 2 + hx][n / 2 + hy + 1] = cnt;
	}
	cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	int n = 1;
	for (int i = 0; i < k; i++) n *= 2;

	int a, b;
	cin >> a >> b;
	int x = n + 1 - b;
	int y = a;
	board[x][y] = -1;

	tile(x, y, n);
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}