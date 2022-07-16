#include <bits/stdc++.h>
using namespace std;
int board[20][20], game_board[20][20];
int N, mx;

void turn(int dir) {
	if (dir == 0) {
		for (int j = 0; j < N; j++) {
			for (int i = 1; i < N; i++) {
				if (board[i][j] == 0) continue;
				/*if (board[i - 1][j] == board[i][j]) {
					board[i - 1][j] *= 2;
					board[i][j] = 0;
				}*/
				//else if (board[i - 1][j] == 0) {
				int t = i - 1;
				while (t >= 0 && board[t][j] == 0) t--;
				if (t >= 0 && board[t][j] == board[i][j]) {
					board[t][j] *= -2;
					board[i][j] = 0;
					continue;
				}
				swap(board[++t][j], board[i][j]);
				//board[i][j] = 0;
					
				//}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = N - 2; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				/*if (board[i - 1][j] == board[i][j]) {
					board[i - 1][j] *= 2;
					board[i][j] = 0;
				}*/
				//else if (board[i - 1][j] == 0) {
				int t = j + 1;
				while (t < N && board[i][t] == 0) t++;
				if (t < N && board[i][t] == board[i][j]) {
					board[i][t] *= -2;
					board[i][j] = 0;
					continue;
				}
				swap(board[i][--t], board[i][j]);
				//board[i][j] = 0;

				//}
			}
		}
	}
	else if (dir == 2) {
		for (int j = 0; j < N; j++) {
			for (int i = N - 2; i >= 0; i--) {
				if (board[i][j] == 0) continue;
				/*if (board[i - 1][j] == board[i][j]) {
					board[i - 1][j] *= 2;
					board[i][j] = 0;
				}*/
				//else if (board[i - 1][j] == 0) {
				int t = i + 1;
				while (t < N && board[t][j] == 0) t++;
				if (t < N && board[t][j] == board[i][j]) {
					board[t][j] *= -2;
					board[i][j] = 0;
					continue;
				}
				swap(board[--t][j], board[i][j]);
				//board[i][j] = 0;

				//}
			}
		}
	}
	else if (dir == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (board[i][j] == 0) continue;
				/*if (board[i - 1][j] == board[i][j]) {
					board[i - 1][j] *= 2;
					board[i][j] = 0;
				}*/
				//else if (board[i - 1][j] == 0) {
				int t = j - 1;
				while (t >= 0 && board[i][t] == 0) t--;
				if (t >= 0 && board[i][t] == board[i][j]) {
					board[i][t] *= -2;
					board[i][j] = 0;
					continue;
				}
				swap(board[i][++t], board[i][j]);
				//board[i][j] = 0;

				//}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] < 0) board[i][j] *= -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> game_board[i][j];
		}
	}
	int times = 1;
	for (int i = 0; i < 5; i++) {
		times *= 4;
	}

	for (int i = 0; i < times - 1; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				board[j][k] = game_board[j][k];
			}
		}
		int tmp = i;
		for (int j = 0; j < 5; j++) {
			int dir = tmp % 4;
			tmp /= 4;
			turn(dir);
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				mx = max(board[j][k], mx);
			}
		}
	}

	cout << mx;
}