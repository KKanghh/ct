#include <bits/stdc++.h>
using namespace std;
int board[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		board[i] += board[i - 1];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << board[j] - board[i - 1] << '\n';
	}

}