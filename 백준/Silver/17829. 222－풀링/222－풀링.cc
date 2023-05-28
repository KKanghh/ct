#include <bits/stdc++.h>
using namespace std;
int board[1024][1024];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	while (n > 1) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				vector<int> V;
				V.push_back(board[2 * i][2 * j]);
				V.push_back(board[2 * i + 1][2 * j]);
				V.push_back(board[2 * i][2 * j + 1]);
				V.push_back(board[2 * i + 1][2 * j + 1]);

				sort(V.begin(), V.end());
				board[i][j] = V[2];
			}
		}

		n /= 2;
	}

	cout << board[0][0];
}