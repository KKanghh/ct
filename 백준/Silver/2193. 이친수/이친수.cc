#include <bits/stdc++.h>
using namespace std;
long long board[91][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	board[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		board[i][0] = board[i - 1][0] + board[i - 1][1];
		board[i][1] = board[i - 1][0];
	}

	cout << board[n][0] + board[n][1];
}