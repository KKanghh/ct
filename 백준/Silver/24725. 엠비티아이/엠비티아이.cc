#include <bits/stdc++.h>
using namespace std;
char MBTI[4][2] = { {'I', 'E'},
{ 'S', 'N' },
{ 'T', 'F' },
{ 'J', 'P' } };

int cnt;
int n, m;
char board[200][200];

int dx[8] = { 0, 1, 1, 1, 0, -1, -1 ,-1 };
int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void check(int i, int j) {
	for (int k = 0; k < 8; k++) {
		if (i + dx[k] * 3 < 0 || i + dx[k] * 3 >= n || j + dy[k] * 3 < 0 || j + dy[k] * 3 >= m) continue;

		if (board[i + dx[k]][j + dy[k]] != 'S' && board[i + dx[k]][j + dy[k]] != 'N') continue;
		if (board[i + dx[k] * 2][j + dy[k] * 2] != 'T' && board[i + dx[k] * 2][j + dy[k] * 2] != 'F') continue;
		if (board[i + dx[k] * 3][j + dy[k] * 3] != 'J' && board[i + dx[k] * 3][j + dy[k] * 3] != 'P') continue;

		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'I' || board[i][j] == 'E') {
				check(i, j);
			}
		}
	}

	cout << cnt;
}