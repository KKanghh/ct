#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	int cnt = 0;
	while (t--) {
		int n;
		cin >> n;
		if (isprime(n)) cnt++;
	}
	cout << cnt;
}