#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int k = b / a;

	int c, d;

	for (int i = 1; i * i <= k; i++) {
		if (k % i == 0) {
			int j;
			for (j = 2; j * j <= i; j++) {
				if (i % j == 0 && (k / i) % j == 0) break;
			}
			if (j * j > i) {
				c = i;
				d = k / i;
			}
		}
	}

	cout << a * c << ' ' << a * d;
}