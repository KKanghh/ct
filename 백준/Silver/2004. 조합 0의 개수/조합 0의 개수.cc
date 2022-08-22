#include <bits/stdc++.h>
using namespace std;

int find(int n, long long k) {
	int res = 0;
	long long p = k;
	while (p <= n) {
		res += n / p;
		p *= k;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int f = find(n, 5) - find(k, 5) - find(n - k, 5);
	int t = find(n, 2) - find(k, 2) - find(n - k, 2);
	cout << min(f, t);
}