#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[100][100];
int vis[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int N, M;
	cin >> N >> M;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j] - '0';
		}
	}
	vis[0][0] = 1;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = Q.front().X + dx[i];
			int ny = Q.front().Y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 0 || vis[nx][ny] > 0) continue;
			vis[nx][ny] = vis[Q.front().X][Q.front().Y] + 1;
			Q.push({ nx, ny });
		}
		Q.pop();
	}

	cout << vis[N - 1][M - 1];

}