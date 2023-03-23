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

void func(int x, int y) {
	if (st == 0) {
		int a = 0;
		for (int i = 1; i <= 5; i++) {
			a += sticker[i];
		}
		mn = min(mn, a);
		return;
	}
	while (x < 10) {
		if (board[x][y] == 1) {
			for (int size = 5; size >= 1; size--) {
				if (sticker[size] == 5) continue;
				if (!check(x, y, size)) continue;

				sticker[size]++;
				st -= size * size;
				attach(x, y, size);
				func(x, y);
				detach(x, y, size);
				st += size * size;
				sticker[size]--;

			}
			return;
		}
		y++;
		if (y == 10) {
			x++;
			y = 0;
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

	func(0, 0);

	if (mn == 0x3f3f3f3f) cout << -1;
	else cout << mn;

}