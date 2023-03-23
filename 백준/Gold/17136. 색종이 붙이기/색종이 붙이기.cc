#include <bits/stdc++.h>
using namespace std;
int board[10][10];
int sticker[6];
int mn = 0x3f3f3f3f, cnt, st;

bool check(int x, int y, int size) {
	for (int dx = 0; dx < size; dx++) {
		for (int dy = 0; dy < size; dy++) {
			if (x + dx >= 10 || y + dy >= 10 || board[x + dx][y + dy] == 0) return false;
		}
	}

	return true;
}

void attach(int x, int y, int size) {
	for (int dx = 0; dx < size; dx++) {
		for (int dy = 0; dy < size; dy++) {
			board[x + dx][y + dy] = 0;
		}
	}
}

void detach(int x, int y, int size) {
	for (int dx = 0; dx < size; dx++) {
		for (int dy = 0; dy < size; dy++) {
			board[x + dx][y + dy] = 1;
		}
	}
}

pair<int, int> find_zero() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j]) return { i, j };
		}
	}
}

void func() {
	if (st == 0) {
		int a = 0;
		for (int i = 1; i <= 5; i++) {
			a += sticker[i];
		}
		mn = min(mn, a);
		return;
	}
	int x, y;
	tie(x, y) = find_zero();
	for (int size = 5; size >= 1; size--) {
		if (sticker[size] < 5 && check(x, y, size)) {
			attach(x, y, size);
			st -= size * size;
			sticker[size]++;
			func();
			sticker[size]--;
			detach(x, y, size);
			st += size * size;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j]) st++;
		}
	}

	func();

	if (mn == 0x3f3f3f3f) cout << -1;
	else cout << mn;

}