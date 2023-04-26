#include <bits/stdc++.h>
using namespace std;

char board[500][500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j] = s[j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == '.') continue;

			if (board[i][j] == 'W') {
				for (int dir = 0; dir < 4; dir++) {
					int x = i + dx[dir];
					int y = j + dy[dir];
					if (x < 0 || x >= r || y < 0 || y >= c) continue;
					if (board[x][y] == 'W') continue;

					if (board[x][y] == 'S') {
						cout << 0;
						return 0;
					}

					board[x][y] = 'D';
				}
			}
		}
	}

	cout << 1 << '\n';

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}