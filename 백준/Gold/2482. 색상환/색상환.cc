#include <bits/stdc++.h>
using namespace std;
int D[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) D[i][1] = i;

	for (int i = 4; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			D[i][j] = (D[i - 1][j] + D[i - 2][j - 1]) % 1000000003;
		}
	}

	cout << D[n][k];
}