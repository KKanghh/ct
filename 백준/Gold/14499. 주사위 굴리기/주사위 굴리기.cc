#include <bits/stdc++.h>
using namespace std;
int board[20][20], N, M, K, x, y, l, r;
deque <int> dice(4);

void rotate_dice(int dir) {
	if (dir == 1) {
		if (y + 1 >= M) return;
		y = y + 1;
		swap(dice[0], r);
		swap(dice[0], dice[2]);
		swap(dice[0], l);
		
	}
	else if (dir == 2) {
		if (y - 1 < 0) return;
		y = y - 1;
		swap(dice[0], l);
		swap(dice[0], dice[2]);
		swap(dice[0], r);
	}
	else if (dir == 3) {
		if (x - 1 < 0) return;
		x -= 1;
		dice.push_back(dice.front());
		dice.pop_front();
	}
	else {
		if (x + 1 >= N) return;
		x += 1;
		dice.push_front(dice.back());
		dice.pop_back();
	}
	if (board[x][y] != 0) {
		dice[2] = board[x][y];
		board[x][y] = 0;
	}
	else {
		board[x][y] = dice[2];
	}
	cout << dice[0] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	while (K--) {
		int dir;
		cin >> dir;
		rotate_dice(dir);
	}
}