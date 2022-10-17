#include <bits/stdc++.h>
using namespace std;
int board[2187][2187];
int cnt[3];

bool check(int a, int b, int n) {
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (board[a][b] != board[i][j]) return false;
		}
	}
	return true;
}
void paper(int a, int b, int n) {
	if (check(a, b, n)) {
		cnt[board[a][b] + 1]++;
		return;
	}
	int k = n / 3;
	for (int i = a; i < a + n; i += k) {
		for (int j = b; j < b + n; j += k) {
			paper(i, j, k);
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	paper(0, 0, n);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}