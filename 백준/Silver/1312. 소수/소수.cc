#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, n;
	int ans = 0;
	cin >> a >> b >> n;

	for (int i = 0; i < n; i++) {
		a %= b;
		a *= 10;
		ans = a / b;
	}

	cout << ans;
}