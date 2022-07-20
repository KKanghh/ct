#include <bits/stdc++.h>
using namespace std;
int board[100][100], N, K, L;
queue<pair <int, int>> snake;
vector<pair<int, char>> turn;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	board[0][0] = 1;
	snake.push({ 0, 0 });

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int a;
		char b;
		cin >> a >> b;
		turn.push_back({ a, b });
	}

	int tik = 0, turn_cur = 0, dir = 0;
	while (true) {
		tik++;
		int x, y;
		tie(x, y) = snake.back();
		if (tik == turn[turn_cur].first + 1) {
			if (turn[turn_cur].second == 'L') {
				dir--;
				if (dir < 0) dir += 4;
			}
			else {
				dir++;
				dir %= 4;
			}
			turn_cur++;
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
		if (board[nx][ny] == 1) break;

		
		if (board[nx][ny] == 0) {
			board[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		snake.push({ nx, ny });
		board[nx][ny] = 1;
	}

	cout << tik;
}