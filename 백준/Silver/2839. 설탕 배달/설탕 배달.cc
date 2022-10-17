#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a = 0;
	while (3 * a <= n) {
		if ((n - 3 * a) % 5 == 0) {
			cout << a + (n - 3 * a) / 5;
			return 0;
		}
		a++;
	}
	cout << -1;
}