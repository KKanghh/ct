#include <bits/stdc++.h>
using namespace std;
int board[1000][1000];
int dist[2][1000][1000];


queue<tuple<int, int, int>> Q;
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			board[i][j] = input[j] - '0';
		}
	}

	Q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		auto a = Q.front();
		Q.pop();
		if (get<1>(a) == N - 1 && get<2>(a) == M - 1) {
			cout << dist[get<0>(a)][get<1>(a)][get<2>(a)];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = get<1>(a) + dx[i];
			int ny = get<2>(a) + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[get<0>(a)][nx][ny] > 0) continue;
			if (board[nx][ny] == 1) {
				if (get<0>(a) == 1) continue;
				else {
					Q.push(make_tuple(1, nx, ny));
					dist[1][nx][ny] = dist[0][get<1>(a)][get<2>(a)] + 1;
				}
			}
			else {
				Q.push(make_tuple(get<0>(a), nx, ny));
				dist[get<0>(a)][nx][ny] = dist[get<0>(a)][get<1>(a)][get<2>(a)] + 1;
			}
		}
	}

	cout << -1;
}