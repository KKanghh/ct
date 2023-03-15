#include <bits/stdc++.h>
using namespace std;
int board[4][4], dir[17];
pair<int, int> p[17];
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int cnt, mx;

void move(int a[4][4], int b[17], pair<int, int> c[17]) {
	int board[4][4] = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = a[i][j];
		}
	}
	int dir[17] = {};
	pair<int, int> p[17] = {};
	for (int i = 0; i <= 16; i++) {
		dir[i] = b[i];
		p[i].first = c[i].first;
		p[i].second = c[i].second; // 가능?
	}
	for (int i = 1; i <= 16; i++) {
		if (p[i].first == -1) continue;
		int x, y;
		tie(x, y) = p[i];
		int d = dir[i];
		int nx = x + dx[dir[i]], ny = y + dy[dir[i]];
		while (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || board[nx][ny] == 0) {
			dir[i] = dir[i] % 8 + 1;
			if (dir[i] == d) {
				nx = x;
				ny = y;
				break;
			}
			nx = x + dx[dir[i]];
			ny = y + dy[dir[i]];
		}
		int j = board[nx][ny];

		if (j == -1) {
			board[x][y] = -1;
			board[nx][ny] = i;
			p[i] = { nx, ny };
		}
		else {
			swap(board[x][y], board[nx][ny]);
			swap(p[i], p[j]);
		}

	}

	vector<int> eat;
	int x, y;
	tie(x, y) = p[0];
	int nx = x + dx[dir[0]], ny = y + dy[dir[0]];
	while (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
		if (board[nx][ny] != -1) eat.push_back(board[nx][ny]);
		nx += dx[dir[0]];
		ny += dy[dir[0]];
	}

	if (eat.size() == 0) {
		mx = max(mx, cnt);
		return;
	}

	for (int i = 0; i < eat.size(); i++) {
		int target = eat[i];
		cnt += target;
		int rx = p[target].first, ry = p[target].second;
		int rdir = dir[0];
		p[0] = { rx, ry };
		p[target] = { -1, -1 };
		board[rx][ry] = 0;
		board[x][y] = -1;
		dir[0] = dir[target];
		move(board, dir, p);
		dir[0] = rdir;
		board[x][y] = 0;
		board[rx][ry] = target;
		p[0] = { x, y };
		p[target] = { rx, ry };
		cnt -= target;
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int fish, head;
			cin >> fish >> head;
			board[i][j] = fish;
			dir[fish] = head;
			p[fish] = { i, j };
		}
	}

	int b;
	b = board[0][0];
	dir[0] = dir[b];
	p[b] = { -1, -1 };
	board[0][0] = 0;
	cnt += b;

	move(board, dir, p);

	cout << mx;

}