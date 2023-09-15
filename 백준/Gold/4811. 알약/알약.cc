#include <bits/stdc++.h>
using namespace std;

long long D[31][31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 30; i++) {
		D[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			D[i][j] = D[i - 1][j] + D[i][j - 1];
		}
	}

	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;
		else cout << D[n][n] << '\n';
	}
}