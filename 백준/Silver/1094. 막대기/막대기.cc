#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 64;
	int x;
	cin >> x;
	int cnt = 0;

	if (x == 64) {
		cout << 1;
		return 0;
	}
	while (x > 0) {
		n /= 2;
		if (n <= x) {
			cnt++;
			x -= n;
		}
	}
	cout << cnt;
}