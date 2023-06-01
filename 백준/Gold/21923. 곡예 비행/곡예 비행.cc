#include <bits/stdc++.h>
using namespace std;
int D[1005][1005];
int up[1005][1005], down[1005][1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> D[i][j];
		}
	}

	for (int i = 1; i <= n + 1; i++) {
		fill(up[i], up[i] + 1005, -0x3f3f3f3f);
		fill(down[i], down[i] + 1005, -0x3f3f3f3f);
	}

	up[n][0] = 0;
	down[n][m + 1] = 0;

	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= m; j++) {
			up[i][j] = max(up[i + 1][j], up[i][j - 1]) + D[i][j];
		}
	}

	

	for (int i = n; i > 0; i--) {
		for (int j = m; j > 0; j--) {
			down[i][j] = max(down[i][j + 1], down[i + 1][j]) + D[i][j];
		}
	}

	int mx = INT_MIN;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			mx = max(mx, up[i][j] + down[i][j]);
		}
	}

	cout << mx;
}