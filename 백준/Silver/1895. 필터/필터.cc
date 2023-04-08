#include <bits/stdc++.h>
using namespace std;
int board[40][40];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, t, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cin >> t;

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			vector<int> V;
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					V.push_back(board[i + x][j + y]);
				}
			}
			sort(V.begin(), V.end());
			if (V[4] >= t) cnt++;
		}
	}

	cout << cnt;

}