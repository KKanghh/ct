#include <bits/stdc++.h>
using namespace std;

int board[101][101];
vector<int> X(1), Y(1), S(1), D(1), Z(1);
bool dead[10001];
int R, C, M, ans;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void shark_move() {
	for (int i = 1; i <= M; i++) {
		if (dead[i]) continue;
		board[X[i]][Y[i]] = 0;
	}
	for (int i = 1; i <= M; i++) {
		if (dead[i]) continue;
		X[i] += dx[D[i]] * S[i];
		Y[i] += dy[D[i]] * S[i];
		while (X[i] < 1 || X[i] > R) {
			if (X[i] < 1) {
				X[i] = 1 + (1 - X[i]);
			}
			else {
				X[i] = R - (X[i] - R);
			}
			D[i] = 1 - D[i];
		}
		while (Y[i] < 1 || Y[i] > C) {
			if (Y[i] < 1) {
				Y[i] = 1 + (1 - Y[i]);
			}
			else {
				Y[i] = C - (Y[i] - C);
			}
			D[i] = 5 - D[i];
		}
		if (board[X[i]][Y[i]] > 0) {
			int tmp = board[X[i]][Y[i]];
			if (Z[tmp] > Z[i]) {
				dead[i] = true;
			}
			else {
				board[X[i]][Y[i]] = i;
				dead[tmp] = true;
			}
		}
		else {
			board[X[i]][Y[i]] = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> M;
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		board[r][c] = i;
		X.push_back(r);
		Y.push_back(c);
		S.push_back(s);
		D.push_back(d - 1);
		Z.push_back(z);
	}

	int fisher = 0;
	while (fisher < C) {
		fisher++;
		for (int x = 1; x <= R; x++) {
			if (board[x][fisher] > 0) {
				dead[board[x][fisher]] = true;
				ans += Z[board[x][fisher]];
				board[x][fisher] = 0;
				break;
			}
		}
		
		shark_move();
	}

	cout << ans;

}