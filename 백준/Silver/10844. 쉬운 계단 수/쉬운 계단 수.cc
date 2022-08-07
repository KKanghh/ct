#include <bits/stdc++.h>
using namespace std;
int D[101][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 9; i++) D[1][i] = 1;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) {
				D[i + 1][j - 1] = (D[i + 1][j - 1] + D[i][j]) % 1000000000;
			}
			if (j + 1 <= 9) {
				D[i + 1][j + 1] = (D[i + 1][j + 1] + D[i][j]) % 1000000000;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans + D[n][i]) % 1000000000;
	}

	cout << ans;
}