#include <bits/stdc++.h>
using namespace std;
int D[1001][10001], I[1001], T[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) cin >> I[i] >> T[i];

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			D[i][j] = D[i - 1][j];
			if (j >= T[i]) D[i][j] = max(D[i][j], D[i - 1][j - T[i]] + I[i]);
		}
	}

	cout << D[k][n];


}