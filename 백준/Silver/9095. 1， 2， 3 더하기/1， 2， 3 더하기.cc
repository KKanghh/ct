#include <bits/stdc++.h>
using namespace std;
int board[12];
int main() {
	int t;
	cin >> t;
	board[1] = 1;
	board[2] = 2;
	board[3] = 4;
	for (int i = 4; i < 12; i++) {
		board[i] = board[i - 1] + board[i - 2] + board[i - 3];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << board[n] << '\n';
	}
}