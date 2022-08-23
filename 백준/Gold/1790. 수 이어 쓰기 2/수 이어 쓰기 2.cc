#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int t = 10, z = 1;
	int i = 1;
	for (; i <= n; i++) {
		if (i == t) {
			t *= 10;
			z++;
		}

		if (k > z) k -= z;
		else {
			for (int j = 0; j < z - k; j++) {
				i /= 10;
			}
			cout << i % 10;
			break;
		}
	}
	if (i == n + 1) cout << -1;
}