#include <bits/stdc++.h>
using namespace std;
int board[1025][1025], D[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + board[i][j];
		}
	}

	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << D[x2][y2] - D[x1 - 1][y2] - D[x2][y1 - 1] + D[x1 - 1][y1 - 1] << '\n';
	}


}