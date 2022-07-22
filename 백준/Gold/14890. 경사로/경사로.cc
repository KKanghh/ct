#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int N, L, cnt;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		int j, st = 1;
		int flag = board[i][0];
		for (j = 1; j < N; j++) {
			if (flag == board[i][j]) {
				st++;
				continue;
			}
			if (abs(flag - board[i][j]) > 1) break;
			if (board[i][j] - flag == 1) {
				if (st >= L) {
					flag = board[i][j];
					st = 1;
				}
				else break;
			}
			else {
				if (st < 0) break;
				flag = board[i][j];
				st = -L + 1;
			}
		}
		if (j == N && st >= 0) cnt++;
	}

	for (int i = 0; i < N; i++) {
		int j, st = 1;
		int flag = board[0][i];
		for (j = 1; j < N; j++) {
			if (flag == board[j][i]) {
				st++;
				continue;
			}
			if (abs(flag - board[j][i]) > 1) break;
			if (board[j][i] - flag == 1) {
				if (st >= L) {
					flag = board[j][i];
					st = 1;
				}
				else break;
			}
			else {
				if (st < 0) break;
				flag = board[j][i];
				st = -L + 1;
			}
		}
		if (j == N && st >= 0) cnt++;
	}

	cout << cnt;
}