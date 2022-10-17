#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[101][101], appear[101];
int r, c, k, tik;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int row = 3, col = 3;
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		fill(appear, appear + 100, 0);
		if (board[r][c] == k) {
			break;
		}
		tik++;
		if (tik > 100) break;
		if (row >= col) {
			int mx = 0;
			for (int i = 1; i <= row; i++) {
				vector<pair<int, int>> V;
				for (int j = 1; j <= col; j++) {
					bool no = true;
					if (board[i][j] == 0) continue;
					for (int k = 0; k < V.size(); k++) {
						if (V[k].Y == board[i][j]) {
							V[k].X++;
							no = false;
							break;
						}
					}
					if (no) V.push_back({ 1, board[i][j] });
					board[i][j] = 0;
				}
				sort(V.begin(), V.end());
				int j = 0;
				for (; j < V.size(); j++) {
					board[i][2 * j + 1] = V[j].Y;
					board[i][2 * j + 2] = V[j].X;
				}
				mx = max(mx, j * 2);
			}
			col = mx;
		}
		else {
			int mx = 0;
			for (int i = 1; i <= col; i++) {
				vector<pair<int, int>> V;
				for (int j = 1; j <= row; j++) {
					bool no = true;
					if (board[j][i] == 0) continue;
					for (int k = 0; k < V.size(); k++) {
						if (V[k].Y == board[j][i]) {
							V[k].X++;
							no = false;
							break;
						}
					}
					if (no) V.push_back({ 1, board[j][i] });
					board[j][i] = 0;
				}
				sort(V.begin(), V.end());
				int j = 0;
				for (; j < V.size(); j++) {
					board[2 * j + 1][i] = V[j].Y;
					board[2 * j + 2][i] = V[j].X;
				}
				mx = max(mx, j * 2);
			}
			row = mx;
		}
	}
	if (tik == 101) tik = -1;
	cout << tik;
}