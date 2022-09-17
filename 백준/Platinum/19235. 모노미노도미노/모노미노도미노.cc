#include <bits/stdc++.h>
using namespace std;
int blue[4][6], green[6][4];
int cnt;

void clear_blue() {
	int clear = 0;
	for (int i = 1; i >= 0; i--) {
		if ((blue[0][i] > 0) || (blue[1][i] > 0) || (blue[2][i] > 0) || (blue[3][i] > 0)) clear++;
	}
	while (clear--) {
		if (blue[0][5] == 4) blue[0][4] = 1;
		blue[0][5] = 0;
		if (blue[1][5] == 4) blue[1][4] = 1;
		blue[1][5] = 0;
		if (blue[2][5] == 4) blue[2][4] = 1;
		blue[2][5] = 0;
		if (blue[3][5] == 4) blue[3][4] = 1;
		blue[3][5] = 0;
		for (int i = 4; i >= 0; i--) {
			swap(blue[0][i], blue[0][i + 1]);
			swap(blue[1][i], blue[1][i + 1]);
			swap(blue[2][i], blue[2][i + 1]);
			swap(blue[3][i], blue[3][i + 1]);
		}
	}
}

void clear_green() {
	int clear = 0;
	for (int i = 1; i >= 0; i--) {
		if ((green[i][0] > 0) || (green[i][1] > 0) || (green[i][2] > 0) || (green[i][3] > 0)) clear++;
	}
	while (clear--) {
		if (green[5][0] == 4) green[4][0] = 1;
		green[5][0] = 0;
		if (green[5][1] == 4) green[4][1] = 1;
		green[5][1] = 0;
		if (green[5][2] == 4) green[4][2] = 1;
		green[5][2] = 0;
		if (green[5][3] == 4) green[4][3] = 1;
		green[5][3] = 0;
		for (int i = 4; i >= 0; i--) {
			swap(green[i][0], green[i + 1][0]);
			swap(green[i][1], green[i + 1][1]);
			swap(green[i][2], green[i + 1][2]);
			swap(green[i][3], green[i + 1][3]);
		}
	}
}

bool blue_chk() {
	bool find = false;
	for (int i = 0; i < 6; i++) {
		if (blue[0][i] > 0 && blue[1][i] > 0 && blue[2][i] > 0 && blue[3][i] > 0) {
			find = true;
			if (blue[0][i] == 2) {
				blue[0][i + 1] = 1;
			}
			else if (blue[0][i] == 4) {
				blue[0][i - 1] = 1;
			}
			blue[0][i] = 0;
			if (blue[1][i] == 2) {
				blue[1][i + 1] = 1;
			}
			else if (blue[1][i] == 4) {
				blue[1][i - 1] = 1;
			}
			blue[1][i] = 0;
			if (blue[2][i] == 2) {
				blue[2][i + 1] = 1;
			}
			else if (blue[2][i] == 4) {
				blue[2][i - 1] = 1;
			}
			blue[2][i] = 0;
			if (blue[3][i] == 2) {
				blue[3][i + 1] = 1;
			}
			else if (blue[3][i] == 4) {
				blue[3][i - 1] = 1;
			}
			blue[3][i] = 0;
			cnt++;
		}
	}
	for (int y = 5; y >= 0; y--) {
		for (int x = 0; x < 4; x++) {
			if (blue[x][y] == 1 || blue[x][y] == 2 || blue[x][y] == 4) {
				int k = y;
				while (k + 1 < 6 && blue[x][k + 1] == 0) k++;
				swap(blue[x][y], blue[x][k]);
			}
			else if (blue[x][y] == 3) {
				int k = y;
				while (k + 1 < 6 && blue[x][k + 1] == 0 && blue[x + 1][k + 1] == 0) k++;
				swap(blue[x][y], blue[x][k]);
				swap(blue[x + 1][y], blue[x + 1][k]);
				x++;
			}
		}

	}
	return find;
}

bool green_chk() {
	bool find = false;
	for (int i = 0; i < 6; i++) {
		if (green[i][0] > 0 && green[i][1] > 0 && green[i][2] > 0 && green[i][3] > 0) {
			find = true;
			if (green[i][0] == 3) {
				green[i + 1][0] = 1;
			}
			else if (green[i][0] == 4) {
				green[i - 1][0] = 1;
			}
			green[i][0] = 0;
			if (green[i][1] == 3) {
				green[i + 1][1] = 1;
			}
			else if (green[i][1] == 4) {
				green[i - 1][1] = 1;
			}
			green[i][1] = 0;
			if (green[i][2] == 3) {
				green[i + 1][2] = 1;
			}
			else if (green[i][2] == 4) {
				green[i - 1][2] = 1;
			}
			green[i][2] = 0;
			if (green[i][3] == 3) {
				green[i + 1][3] = 1;
			}
			else if (green[i][3] == 4) {
				green[i - 1][3] = 1;
			}
			green[i][3] = 0;
			cnt++;
		}
	}
	for (int x = 5; x >= 0; x--) {
		for (int y = 0; y < 4; y++) {
			if (green[x][y] == 1 || green[x][y] == 3 || green[x][y] == 4) {
				int k = x;
				while (k + 1 < 6 && green[k + 1][y] == 0) k++;
				swap(green[x][y], green[k][y]);
			}
			else if (green[x][y] == 2) {
				int k = x;
				while (k + 1 < 6 && green[k + 1][y] == 0 && green[k + 1][y + 1] == 0) k++;
				swap(green[x][y], green[k][y]);
				swap(green[x][y + 1], green[k][y + 1]);
				y++;
			}
		}
	}
	return find;
}

void block(int t, int x, int y) {
	if (t == 1) {
		int ny = 0;
		while (ny + 1 < 6 && blue[x][ny + 1] == 0) ny++;
		blue[x][ny] = 1;
		int nx = 0;
		while (nx + 1 < 6 && green[nx + 1][y] == 0) nx++;
		green[nx][y] = 1;
	}
	else if (t == 2) {
		int ny = 0;
		while (ny + 1 < 6 && blue[x][ny + 1] == 0) ny++;
		blue[x][ny] = 4;
		blue[x][--ny] = 2;
		int nx = 0;
		while (nx + 1 < 6 && green[nx + 1][y] == 0 && green[nx + 1][y + 1] == 0) nx++;
		green[nx][y] = 2;
		green[nx][y + 1] = 2;
	}
	else if (t == 3) {
		int ny = 0;
		while (ny + 1 < 6 && blue[x][ny + 1] == 0 && blue[x + 1][ny + 1] == 0) ny++;
		blue[x][ny] = 3;
		blue[x + 1][ny] = 3;
		int nx = 0;
		while (nx + 1 < 6 && green[nx + 1][y] == 0) nx++;
		green[nx][y] = 4;
		green[--nx][y] = 3;
	}

	while (blue_chk());
	clear_blue();
	while (green_chk());
	clear_green();

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (n--) {
		int t, x, y;
		cin >> t >> x >> y;
		block(t, x, y);
	}
	cout << cnt << '\n';
	int is_block = 0;
	for (int i = 2; i < 6; i++) {
		is_block += (green[i][0] > 0) + (green[i][1] > 0) + (green[i][2] > 0) + (green[i][3] > 0) + (blue[0][i] > 0) + (blue[1][i] > 0) + (blue[2][i] > 0) + (blue[3][i] > 0);
	}
	cout << is_block;
}