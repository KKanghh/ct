#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 1;
	while (true) {
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		int n = v / p * l;
		n += v % p > l ? l : v % p;
		cout << "Case " << cnt++ << ": " << n << '\n';
	}
}