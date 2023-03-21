#include <bits/stdc++.h>
using namespace std;

int board[17][17];
int cnt, n;

void go(pair<int, int> a, int b) {
	if (a.first + b / 2 > n ||
		a.second + b % 2 > n ||
		board[a.first][a.second + b % 2] == 1 ||
		board[a.first + b / 2][a.second] == 1 ||
		board[a.first + b / 2][a.second + b % 2] == 1) return;
	if (b == 1 && a.second + 1 == n) {
		if (a.first == n) cnt++;
		return;
	}
	else if (b == 2 && a.first + 1 == n) {
		if (a.second == n) cnt++;
		return;
	}
	else if (b == 3 && a.first + 1 == n && a.second + 1 == n) {
		cnt++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (b == 1 && i == 2 || i == 1 && b == 2) continue;
		pair<int, int> k = { a.first + b / 2, a.second + b % 2 };

		go(k, i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	go({ 1, 1 }, 1);
	cout << cnt;

}