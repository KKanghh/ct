#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char pic[100][100];
int area1[100][100], area2[100][100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int num;
	cin >> num;

	int normal_area = 0, RG_area = 0;
	for (int i = 0; i < num; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < num; j++) {
			pic[i][j] = input[j];
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (area1[i][j] == 0) {
				int now_area = ++normal_area;
				char color = pic[i][j];
				area1[i][j] = now_area;
				Q.push({ i,j });

				while (!Q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = Q.front().X + dx[k];
						int ny = Q.front().Y + dy[k];
						if (nx < 0 || nx >= num || ny < 0 || ny >= num) continue;
						if (pic[nx][ny] != color || area1[nx][ny] != 0) continue;
						area1[nx][ny] = now_area;
						Q.push({ nx, ny });
					}
					Q.pop();
					
				}
			}
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (pic[i][j] == 'R') pic[i][j] = 'G';
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (area2[i][j] == 0) {
				int now_area = ++RG_area;
				char color = pic[i][j];
				area2[i][j] = now_area;
				Q.push({ i,j });

				while (!Q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = Q.front().X + dx[k];
						int ny = Q.front().Y + dy[k];
						if (nx < 0 || nx >= num || ny < 0 || ny >= num) continue;
						if (pic[nx][ny] != color || area2[nx][ny] != 0) continue;
						area2[nx][ny] = now_area;
						Q.push({ nx, ny });
					}
					Q.pop();

				}
			}
		}
	}

	cout << normal_area << ' ' << RG_area;
}