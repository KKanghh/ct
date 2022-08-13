#include <bits/stdc++.h>
using namespace std;
int D[100001][3], a[100001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}

		D[1][1] = a[1][1];
		D[1][2] = a[1][1] + a[1][2];
		D[2][0] = a[1][1] + a[2][0];
		D[2][1] = min({ D[1][1], D[1][2], D[2][0] }) + a[2][1];
		D[2][2] = min({ D[1][1], D[1][2], D[2][1] }) + a[2][2];

		for (int i = 3; i <= n; i++) {
			D[i][0] = min({ D[i - 1][0], D[i - 1][1] }) + a[i][0];
			D[i][1] = min({ D[i - 1][0], D[i - 1][1], D[i - 1][2], D[i][0] }) + a[i][1];
			D[i][2] = min({ D[i - 1][1], D[i - 1][2], D[i][1] }) + a[i][2];
		}

		cout << k++ << ". " << D[n][1] << '\n';
	}
}