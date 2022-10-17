#include <bits/stdc++.h>
using namespace std;
int board[13][13];
deque<int> D[13][13];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
vector <int> X, Y, DIR;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		X.push_back(x);
		Y.push_back(y);
		DIR.push_back(dir - 1);
		D[x][y].push_back(i);
	}

	int turn = 1;
	bool finish = false;
	while (turn <= 1000) {
		for (int i = 0; i < k; i++) {
			int x, y, dir;
			x = X[i];
			y = Y[i];
			dir = DIR[i];
			deque<int> Q;
			while (D[x][y].back() != i) {
				Q.push_front(D[x][y].back());
				D[x][y].pop_back();
			}
			Q.push_front(D[x][y].back());
			D[x][y].pop_back();
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			for (int t = 0; t < 2; t++) {
				if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 2) {
					if (t == 1) {
						while (!Q.empty()) {
							D[x][y].push_back(Q.front());
							Q.pop_front();
						}
						DIR[i] = dir;
						break;
					}
					if (dir < 2) {
						dir = 1 - dir;
					}
					else dir = 5 - dir;
					nx = x + dx[dir];
					ny = y + dy[dir];
				}
				else if (board[nx][ny] == 0) {
					while (!Q.empty()) {
						D[nx][ny].push_back(Q.front());
						X[Q.front()] = nx;
						Y[Q.front()] = ny;
						Q.pop_front();
					}
					DIR[i] = dir;
					if (D[nx][ny].size() >= 4) finish = true;
					break;
				}
				else {
					while (!Q.empty()) {
						D[nx][ny].push_back(Q.back());
						X[Q.back()] = nx;
						Y[Q.back()] = ny;
						Q.pop_back();
					}
					DIR[i] = dir;
					if (D[nx][ny].size() >= 4) finish = true;
					break;
				}
			}
			
		}
		if (finish) break;
		turn++;
	}

	if (turn == 1001) turn = -1;
	cout << turn;
}