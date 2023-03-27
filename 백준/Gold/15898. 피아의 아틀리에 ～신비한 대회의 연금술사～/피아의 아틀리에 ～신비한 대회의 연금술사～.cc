#include <bits/stdc++.h>
using namespace std;
int effect[10][4][4];
char element[10][4][4];
int board[5][5];
char el_board[5][5];
int mx;

void put(int num, int pl, int dir) {
	int temp_effect[4][4];
	char temp_element[4][4];
	if (dir == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp_effect[i][j] = effect[num][i][j];
				temp_element[i][j] = element[num][i][j];
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp_effect[i][j] = effect[num][3 - j][i];
				temp_element[i][j] = element[num][3 - j][i];
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp_effect[i][j] = effect[num][3 - i][3 - j];
				temp_element[i][j] = element[num][3 - i][3 - j];
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp_effect[i][j] = effect[num][j][3 - i];
				temp_element[i][j] = element[num][j][3 - i];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[pl / 2 + i][pl % 2 + j] += temp_effect[i][j];
			if (temp_element[i][j] != 'W') el_board[pl / 2 + i][pl % 2 + j] = temp_element[i][j];
			if (board[pl / 2 + i][pl % 2 + j] > 9) board[pl / 2 + i][pl % 2 + j] = 9;
			else if (board[pl / 2 + i][pl % 2 + j] < 0) board[pl / 2 + i][pl % 2 + j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> effect[i][j][k];
			}
		}

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> element[i][j][k];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int nums[3] = { i, j, k };
				do {
					for (int a = 0; a < 64; a++) {
						for (int b = 0; b < 64; b++) {
						
							for (int c = 0; c < 5; c++) {
								fill(board[c], board[c] + 5, 0);
								fill(el_board[c], el_board[c] + 5, 'W');
							}
							int ta = a;
							int tb = b;


							for (int c = 0; c < 3; c++) {
								put(nums[c], ta % 4, tb % 4);
								ta /= 4;
								tb /= 4;
							}

							int red = 0, blue = 0, green = 0, yellow = 0;
							for (int x = 0; x < 5; x++) {
								for (int y = 0; y < 5; y++) {
									if (el_board[x][y] == 'R') red += board[x][y];
									else if (el_board[x][y] == 'B') blue += board[x][y];
									else if (el_board[x][y] == 'G') green += board[x][y];
									else if (el_board[x][y] == 'Y') yellow += board[x][y];
								}
							}

							mx = max(mx, 7 * red + 5 * blue + 3 * green + 2 * yellow);
						
						}
					}
				} while (next_permutation(nums, nums + 3));
			}
		}
	}

	cout << mx;
}