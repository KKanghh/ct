#include <bits/stdc++.h>
using namespace std;
string board[3072];

void make(int n) {
	if (n == 3) {
		board[0].append("  *  ");
		board[1].append(" * * ");
		board[2].append("*****");
		return;
	}
	make(n / 2);
	for (int i = 0; i < n / 2; i++) {
		string temp = board[i];
		board[n / 2 + i] = board[i] + " " + board[i];
		for (int j = 0; j < n / 2; j++) {
			board[i].insert(0, " ");
			board[i].append(" ");
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	make(N);
	for (int i = 0; i < N; i++) cout << board[i] << '\n';
}