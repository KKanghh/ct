#include <bits/stdc++.h>
using namespace std;
int D[2][100000], a[2][100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a[1][i];
		}

		D[0][0] = a[0][0];
		D[1][0] = a[1][0];
		D[0][1] = a[1][0] + a[0][1];
		D[1][1] = a[0][0] + a[1][1];

		for (int i = 2; i < n; i++) {
			D[0][i] = max(D[1][i - 1], D[1][i - 2]) + a[0][i];
			D[1][i] = max(D[0][i - 1], D[0][i - 2]) + a[1][i];
		}

		cout << max(D[0][n - 1], D[1][n - 1]) << '\n';
	}

}