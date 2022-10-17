#include <bits/stdc++.h>
using namespace std;
string board[6561];

void make(int n) {
	if (n == 1) {
		board[0] = '*';
		return;
	}
	make(n / 3);
	int i = 0;
	for (; i < n / 3; i++) {
		string temp = board[i];
		board[i].append(temp);
		board[i].append(temp);
		board[i + n / 3] = temp;
	}
	for (; i < n / 3 * 2; i++) {
		string temp = board[i];
		string blank = " ";
		for (int j = 0; j < n / 3; j++) {
			board[i].append(blank);
		}
		board[i].append(temp);
	}
	for (; i < n; i++) {
		board[i] = board[n - 1 - i];
	}

}

int main() {
	int N;
	cin >> N;
	make(N);
	for (int i = 0; i < N; i++) {
		cout << board[i] << '\n';
	}
}