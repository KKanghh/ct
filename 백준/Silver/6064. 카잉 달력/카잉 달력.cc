#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int m, n, x, y;
		bool find = false;
		cin >> m >> n >> x >> y;

		for (int i = x; i <= m * n; i += m) {
			if ((i - y) % n == 0) {
				cout << i << '\n';
				find = true;
				break;
			}
		}

		if (!find) cout << -1 << '\n';
	}
}