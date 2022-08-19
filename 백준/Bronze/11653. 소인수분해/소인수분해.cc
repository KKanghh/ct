#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k = 2;
	while (k <= n) {
		while (n % k == 0) {
			n /= k;
			cout << k << '\n';
		}
		k++;
	}
}