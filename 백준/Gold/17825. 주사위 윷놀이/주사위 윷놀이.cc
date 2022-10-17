#include <bits/stdc++.h>
using namespace std;
int board[22][9] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{2, 0, 0 ,0 ,0 ,0, 0 ,0, 0},
	{4, 0, 0, 0, 0, 0, 0, 0, 0},
	{6, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{8, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{10, 13, 16, 19, 25, 30 ,35 ,40, 0},
	{12, 0, 0, 0, 0, 0, 0, 0, 0},
	{14, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{16, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{18, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{20, 22, 24, 25, 30, 35, 40, 0, 0},
	{22, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{24, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{26, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{28, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{30, 28, 27, 26, 25, 30, 35, 40, 0},
	{32, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{34, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{36, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{38, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{40, 0, 0, 0, 0, 0 ,0 ,0, 0},
	{0, 0, 0, 0, 0, 0 ,0 ,0, 0}
};

int arr[10] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3 };

int player_loc[22][9];

pair<int, int> player[4];
bool finish[4];
int D[4];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

void is_finished(int i) {
	int x, y;
	tie(x, y) = player[i];

	if (x == 21 && y == 0) finish[i] = true;
	else if (x % 5 == 0 && y == 8) finish[i] = true;
}
int dice[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mx = 0;

	int t = 1;
	for (int i = 0; i < 10; i++) {
		t *= 4;
		cin >> dice[i];
	}

	for (int i = 0; i < t; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			player[j] = { 0, 0 };
			finish[j] = false;
			D[j] = 0;
		}
		for (int j = 0; j < 22; j++) {
			fill(player_loc[j], player_loc[j] + 9, -1);
		}
		int tmp = i;
		for (int j = 0; j < 10; j++) {
			int a = tmp % 4;
			tmp /= 4;
			if (finish[a]) break;
			int x, y;
			tie(x, y) = player[a];
			player_loc[x][y] = -1;
			int nx = x + dx[D[a]] * dice[j];
			int ny = y + dy[D[a]] * dice[j];
			
			if (nx >= 21) {
				finish[a] = true;
				nx = 21;
			}
			if (nx == 5 || nx == 15) {
				if (ny >= 8) {
					finish[a] = true;
					ny = 8;
				}
				else if (ny >= 4) {
					nx = 10;
					ny -= 1;
				}
				
			}
			if (nx == 10 && ny >= 7) {
				finish[a] = true;
				ny = 7;
			}

			if (nx == 20) {
				nx = 10;
				ny = 6;
			}
			if (nx % 5 == 0) D[a] = 1;
			if (player_loc[nx][ny] > -1) break;
			if (!finish[a]) player_loc[nx][ny] = a;
			cnt += board[nx][ny];
			player[a] = { nx, ny };
		}

		mx = max(mx, cnt);
	}

	cout << mx;
}