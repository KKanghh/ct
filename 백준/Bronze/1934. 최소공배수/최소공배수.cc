#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;

		int mn = min(a, b);
		for (; mn > 1; mn--) {
			if (a % mn == 0 && b % mn == 0) break;
		}

		cout << a * b / mn << '\n';
	}
}