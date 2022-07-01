#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int S[10], ans[10];
queue<tuple<int, int, int, int>> Q, turn_Q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, P;
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int p = 1; p <= P; p++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (board[n][m] - '0' == p) Q.push({ 1, p, n, m });
			}
		}
	}

	int move, team, x, y;
	int turn = 1;
	while (!Q.empty()) {
		while (!Q.empty() && get<1>(Q.front()) == turn) {
			turn_Q.push(Q.front());
			Q.pop();
		}
		turn = turn % P + 1;
		while (!turn_Q.empty()) {
			tie(move, team, x, y) = turn_Q.front();
			turn_Q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (board[nx][ny] != '.') continue;
				if (move < S[team]) {
					board[nx][ny] = team + '0';
					turn_Q.push({ move + 1, team, nx, ny });
				}
				else {
					board[nx][ny] = team + '0';
					Q.push({ 1, team, nx, ny });
				}
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (board[n][m] == '#' || board[n][m] == '.') continue;
			ans[board[n][m] - '0']++;
		}
	}

	for (int i = 1; i <= P; i++) {
		cout << ans[i] << ' ';
	}
}

