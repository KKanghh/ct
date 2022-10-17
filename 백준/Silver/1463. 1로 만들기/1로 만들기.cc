#include <bits/stdc++.h>
using namespace std;
int board[1000001];
queue<int> Q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	board[1] = 0;
	Q.push(1);
	while (true) {
		int i = Q.front();
		Q.pop();
		if (i == n) break;
		if (2 * i < 1000001 && board[2 * i] == 0) {
			board[2 * i] = board[i] + 1;
			Q.push(2 * i);
		}
		if (3 * i < 1000001 && board[3 * i] == 0) {
			board[3 * i] = board[i] + 1;
			Q.push(3 * i);
		}
		if (i + 1 < 1000001 && board[i + 1] == 0) {
			board[i + 1] = board[i] + 1;
			Q.push(i + 1);
		}
	}
	cout << board[n];
}