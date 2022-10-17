#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int team[20][20];
int ppl[5];
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			k += board[i][j];
		}
	}

	int mn = 0x7f7f7f7f;

	for (int d1 = 1; d1 < n; d1++) {
		for (int d2 = 1; d2 < n; d2++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (x + d1 + d2 >= n) continue;
					if (y - d1 < 0 || y + d2 >= n) continue;
					fill(ppl, ppl + 5, 0);
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							if (i < x + d1 && j <= y && i + j < x + y) {
								ppl[0] += board[i][j];
								team[i][j] = 1;
							}
							else if (i <= x + d2 && y < j && j - i > y - x) {
								ppl[1] += board[i][j];
								team[i][j] = 2;
							}
							else if (i >= x + d1 && j < y - d1 + d2 && y - x > j - i + 2 * d1) {
								ppl[2] += board[i][j];
								team[i][j] = 3;
							}
							else if (i > x + d2 && y - d1 + d2 <= j && i + j > x + y + 2 * d2) {
								ppl[3] += board[i][j];
								team[i][j] = 4;
							}
							else {
								ppl[4] += board[i][j];
								team[i][j] = 5;
							}
						}
					}
					sort(ppl, ppl + 5);
					mn = min(ppl[4] - ppl[0], mn);
				}
			}
		}
	}
	
	cout << mn;
}