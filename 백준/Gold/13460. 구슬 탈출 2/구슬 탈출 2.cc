#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[10][10], game[10][10];
int N, M, lim = 1, mn = 11;
vector <pair<int, int>> marble;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool red, blue;

void tilt(int num, int dir) {
	int x, y;
	tie(x, y) = marble[num];
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	while (game[nx][ny] == '.' || game[nx][ny] == 'O') {
		if (game[nx][ny] == 'O') {
			if (game[x][y] == 'R') {
				red = true;
			}
			else if (game[x][y] == 'B') {
				blue = true;
			}
			game[x][y] = '.';
			return;
		}
		nx += dx[dir];
		ny += dy[dir];
	}
	nx -= dx[dir];
	ny -= dy[dir];
	marble[num].X = nx;
	marble[num].Y = ny;
	swap(game[nx][ny], game[x][y]);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int red_x, red_y, blue_x, blue_y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				marble.push_back({ i, j });
				red_x = i;
				red_y = j;
			}
			if (board[i][j] == 'B') {
				marble.push_back({ i, j });
				blue_x = i;
				blue_y = j;
			}
		}
	}

	for (int i = 0; i < 10; i++) lim *= 4;

	for (int cases = 0; cases < lim; cases++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				game[i][j] = board[i][j];
			}
		};
		red = false, blue = false;
		marble[0].X = red_x;
		marble[0].Y = red_y;
		marble[1].X = blue_x;
		marble[1].Y = blue_y;
		int tmp = cases;
		for (int k = 1; k <= 10; k++) {
			sort(marble.begin(), marble.end());
			int dir = tmp % 4;
			tmp /= 4;

			if (dir < 2) {
				tilt(0, dir);
				tilt(1, dir);
			}
			else {
				tilt(1, dir);
				tilt(0, dir);
			}
			if (blue) {
				break;
			}
			if (red) {
				mn = min(mn, k);
				break;
				
			}
		}
	}
	if (mn == 11) mn = -1;
	cout << mn;

}