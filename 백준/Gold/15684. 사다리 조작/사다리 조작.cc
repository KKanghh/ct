#include <bits/stdc++.h>
using namespace std;
bool sdr[31][11], selected[270], sdr_copy[31][11];
int N, M, H;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		int garo, sero;
		cin >> garo >> sero;
		sdr[garo][sero] = true;
	}

	for (int i = 0; i <= 3; i++) {
		fill(selected, selected + (N - 1) * H, true);
		fill(selected, selected + i, false);

		do {
			bool find = true;
			for (int x = 0; x < 31; x++) {
				for (int y = 0; y < 11; y++) {
					sdr_copy[x][y] = sdr[x][y];
				}
			}

			for (int k = 0; k < (N - 1) * H; k++) {
				if (selected[k]) continue;
				int x = k / (N - 1) + 1;
				int y = k % (N - 1) + 1;
				if (sdr_copy[x][y] || sdr_copy[x][y - 1] || sdr_copy[x][y + 1]) break;
				sdr_copy[x][y] = true;
			}

			for (int k = 1; k <= N; k++) {
				int x = k;
				for (int t = 1; t <= H; t++) {
					if (sdr_copy[t][x]) x++;
					else if (sdr_copy[t][x - 1]) x--;
				}
				if (x != k) {
					find = false;
					break;
				}
			}

			if (find) {
				cout << i;
				return 0;
			}
		} while(next_permutation(selected, selected + (N - 1) * H));
	}

	cout << -1;
}