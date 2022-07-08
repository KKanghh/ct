#include <bits/stdc++.h>
using namespace std;
int n, cnt;
bool board[15][15];

bool check(int x, int y) {
	int i = x, j = y;
	while (i >= 0 && j >= 0) {
		if (board[i][j]) return false;
		i--; j--;
	}
	i = x, j = y;
	while (i >= 0 && j < n) {
		if (board[i][j]) return false;
		i--; j++;
	}
	i = x, j = y;
	while (i >= 0) {
		if (board[i][j]) return false;
		i--;
	}
	return true;
}

void func(int k) {
	if (k == n) {
		cnt++;
	}
	for (int i = 0; i < n; i++) {
		if (check(k, i)) {
			board[k][i] = true;
			func(k + 1);
			board[k][i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;
}
