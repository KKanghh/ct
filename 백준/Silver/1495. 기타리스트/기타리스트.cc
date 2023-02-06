#include <bits/stdc++.h>
using namespace std;
int n, m, s, V[51];
bool D[51][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) cin >> V[i];

	D[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j + V[i] <= m) D[i][j] = D[i - 1][j + V[i]] || D[i][j];
			if (j - V[i] >= 0) D[i][j] = D[i - 1][j - V[i]] || D[i][j];
		}
	}

	for (int i = m; i >= 0; i--) {
		if (D[n][i]) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
}