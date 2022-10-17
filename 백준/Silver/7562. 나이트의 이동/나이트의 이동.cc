#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[300][300];

int main() {
	int test;
	cin >> test;
	queue<pair<int, int>> Q;

	int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	while (test--) {
		int N, now_x, now_y, goal_x, goal_y;
		cin >> N >> now_x >> now_y >> goal_x >> goal_y;
		board[now_x][now_y] = 1;
		Q.push({ now_x, now_y });
		while (board[goal_x][goal_y] == 0) {
			for (int i = 0; i < 8; i++) {
				int nx = Q.front().X + dx[i];
				int ny = Q.front().Y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (board[nx][ny] != 0) continue;
				board[nx][ny] = board[Q.front().X][Q.front().Y] + 1;
				Q.push({ nx, ny });
			}
			Q.pop();
		}

		cout << board[goal_x][goal_y] - 1<< '\n';
		while (!Q.empty()) Q.pop();
		for (int i = 0; i < N; i++) {
			fill(board[i], board[i] + N, 0);
		}

	}
}