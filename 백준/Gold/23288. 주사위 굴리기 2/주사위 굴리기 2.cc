#include <bits/stdc++.h>
using namespace std;

int dice[4][3] = { {0, 2, 0},
	{4, 1, 3},
	{0, 5, 0},
	{0, 6, 0} };
int n, m, k, head;
int board[21][21];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int x = 1, y = 1;
int score;
bool vis[21][21];

void spin() {
	int nx = x + dx[head];
	int ny = y + dy[head];
	if (nx <= 0 || nx > n || ny <= 0 || ny > m) {
		head = (head + 2) % 4;
		nx = x + dx[head];
		ny = y + dy[head];
	}

	if (head == 0) {
		int temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;
	}
	else if (head == 1) {
		int temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;
	}
	else if (head == 2) {
		int temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;
	}
	else {
		int temp = dice[3][1];
		dice[3][1] = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = temp;
	}
	x = nx;
	y = ny;
}

void get_score() {
	for (int i = 1; i <= n; i++) {
		fill(vis[i] + 1, vis[i] + m + 1, false);
	}
	queue<pair<int, int>> Q;
	Q.push({ x, y });
	vis[x][y] = true;
	int cnt = 1;
	while (!Q.empty()) {
		int cx, cy;
		tie(cx, cy) = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (board[nx][ny] != board[x][y] || vis[nx][ny]) continue;
			cnt++;
			vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}

	score += cnt * board[x][y];
}

void set_dir() {
	int A = dice[3][1];
	int B = board[x][y];

	if (A > B) {
		head = (head + 1) % 4;
	}
	else if (A < B) {
		head = (head + 3) % 4;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	while (k--) {
		spin();
		get_score();
		set_dir();
	}


	cout << score;

}