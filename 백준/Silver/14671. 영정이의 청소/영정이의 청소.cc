#include <bits/stdc++.h>
using namespace std;
bool board[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x % 2][y % 2] = true;
	}

	if (board[0][0] && board[0][1] && board[1][0] && board[1][1]) cout << "YES";
	else cout << "NO";
}