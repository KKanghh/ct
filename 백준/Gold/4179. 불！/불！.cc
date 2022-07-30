#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char maze[1000][1000];
int jd[1000][1000];
int fd[1000][1000];
queue<pair<int, int>> JQ;
queue<pair<int, int>> FQ;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j< M; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'J') {
				jd[i][j] = 1;
				JQ.push({ i, j });
			}
			if (maze[i][j] == 'F') {
				fd[i][j] = 1;
				FQ.push({ i, j });
			}
		}
	}

	while (!FQ.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = FQ.front().X + dx[i];
			int ny = FQ.front().Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (maze[nx][ny] == '#' || fd[nx][ny] > 0) continue;
			fd[nx][ny] = fd[FQ.front().X][FQ.front().Y] + 1;
			FQ.push({ nx, ny });
		}
		FQ.pop();
	}

	while (!JQ.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = JQ.front().X + dx[i];
			int ny = JQ.front().Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				cout << jd[JQ.front().X][JQ.front().Y];
				return 0;
			}
			if (maze[nx][ny] == '#' || jd[nx][ny] > 0 ||(fd[nx][ny] > 0 && fd[nx][ny] <= jd[JQ.front().X][JQ.front().Y] + 1)) continue;
			jd[nx][ny] = jd[JQ.front().X][JQ.front().Y] + 1;
			JQ.push({ nx, ny });
		}
		JQ.pop();
	}

	cout << "IMPOSSIBLE";

}