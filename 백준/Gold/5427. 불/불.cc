#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char M[1000][1000];
int fd[1000][1000], sd[1000][1000];
queue<pair<int, int>> fq, sq;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int w, h;

void BFS() {
	while (!sq.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = sq.front().X + dx[i];
			int ny = sq.front().Y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				cout << sd[sq.front().X][sq.front().Y] << '\n';
				while (!sq.empty()) sq.pop();
				return;
			}
			if (M[nx][ny] == '#' || sd[nx][ny] > 0) continue;
			if (fd[nx][ny] > 0 && fd[nx][ny] <= sd[sq.front().X][sq.front().Y] + 1) continue;
			sd[nx][ny] = sd[sq.front().X][sq.front().Y] + 1;
			sq.push({ nx, ny });
		}
		sq.pop();
	}
	cout << "IMPOSSIBLE\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test;
	cin >> test;

	while (test--) {

		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string input;
			cin >> input;
			for (int j = 0; j < w; j++) {
				M[i][j] = input[j];
				if (M[i][j] == '*') {
					fd[i][j] = 1;
					fq.push({ i, j });
				}
				else if (M[i][j] == '@') {
					sd[i][j] = 1;
					sq.push({ i, j });
				}
			}
		}
		
		while (!fq.empty()) {
			for (int i = 0; i < 4; i++) {
				int nx = fq.front().X + dx[i];
				int ny = fq.front().Y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (M[nx][ny] == '#' || fd[nx][ny] != 0) continue;
				fd[nx][ny] = fd[fq.front().X][fq.front().Y] + 1;
				fq.push({ nx, ny });
			}
			fq.pop();
		}

		BFS();
		
		
		for (int i = 0; i < h; i++) {
			fill(M[i], M[i] + w, 0);
			fill(sd[i], sd[i] + w, 0);
			fill(fd[i], fd[i] + w, 0);
		}

	}
}