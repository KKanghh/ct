#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, m;
	cin >> a >> b >> c >> m;

	int p = 0, w = 0;

	for (int i = 0; i < 24; i++) {
		if (p + a <= m) {
			w += b;
			p += a;
		} else {
			p -= c;
			if (p < 0) p = 0;
		}
	}

	cout << w;
}