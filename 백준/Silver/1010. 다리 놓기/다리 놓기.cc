#include <bits/stdc++.h>
using namespace std;
int C[31][31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	;

	C[0][0] = 1;
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << C[m][n] << '\n';
	}
}