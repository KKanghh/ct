#include <bits/stdc++.h>
using namespace std;
int N, M, K, R, C, cnt;
long long board[40];
long long sticker[10];

void rotate() {
	long long temp[10] = {};
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			
			temp[i] = (temp[i] << 1) + sticker[j] % 2;
			sticker[j] = (sticker[j] >> 1);
		}
	}
	for (int i = 0; i < 10; i++) {
		sticker[i] = temp[i];
	}
	swap(R, C);
}

bool find() {
	for (int j = 0; j < 4; j++) {
		if (R > N || C > M) {
			rotate();
			continue;
		}
		for (int a = 0; a <= N - R; a++) {
			long long tmp[10] = {};
			for (int k = 0; k < R; k++) tmp[k] = sticker[k];
			for (int b = 0; b <= M - C; b++) {
				bool isfit = true;
				for (int c = 0; c < R; c++) {
					if ((tmp[c] & board[c + a]) > 0) isfit = false;
				}
				if (isfit) {
					for (int c = 0; c < R; c++) {
						board[c + a] = (board[c + a] | tmp[c]);
					}
					return true;
				}
				for (int k = 0; k < R; k++) {
					tmp[k] = (tmp[k] << 1);
				}
			}
		}
		rotate();
	}
	return false;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		fill(sticker, sticker + 10, 0);
		int paint = 0;
		cin >> R >> C;
		for (int a = 0; a < R; a++) {
			for (int b = 0; b < C; b++) {
				int tmp;
				cin >> tmp;
				if (tmp == 1) paint++;
				tmp = (tmp << b);
				sticker[a] += tmp;
			}
		}

		if (find()) {
			cnt += paint;
		}
		
	}
	
	cout << cnt;
}