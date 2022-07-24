#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[50][50];
int united[50][50];
int N, L, R;
int country;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

queue<pair<int, int>> Q;

void div() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (united[i][j] == -1) {
				Q.push({ i, j });
				united[i][j] = country;
				while (!Q.empty()) {
					int x, y;
					tie(x, y) = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (united[nx][ny] != -1 || abs(board[x][y] - board[nx][ny]) < L || abs(board[x][y] - board[nx][ny]) > R) continue;
						Q.push({ nx, ny });
						united[nx][ny] = country;
					}
				}
				country++;
			}
		}
	}
}


void refugee() {
	int coun_cnt[2500] = {}, pop_cnt[2500] = {};
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			coun_cnt[united[x][y]]++;
			pop_cnt[united[x][y]] += board[x][y];
		}
	}

	for (int i = 0; i < country; i++) {
		pop_cnt[i] /= coun_cnt[i];
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			board[x][y] = pop_cnt[united[x][y]];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
		}
	}
	int day = 0;
	
	while (true) {
		for (int i = 0; i < N; i++) {
			fill(united[i], united[i] + N, -1);
		}
		country = 0;
		div();
		if (country == N * N) break;
		day++;
		refugee();

	}
	cout << day;
}