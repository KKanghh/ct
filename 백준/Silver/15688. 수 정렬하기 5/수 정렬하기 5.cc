#include <bits/stdc++.h>
using namespace std;
int board[2000001], n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		board[tmp + 1000000]++;
	}

	for (int i = 0; i < 2000001; i++) {
		if (board[i] > 0) {
			for (int j = 0; j < board[i]; j++) {
				cout << i - 1000000 << '\n';
			}
		}
	}

}