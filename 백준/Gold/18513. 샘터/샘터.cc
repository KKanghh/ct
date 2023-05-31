#include <bits/stdc++.h>
using namespace std;
queue<pair<long long, long long>> Q;
unordered_set<int> S;
long long sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		S.insert(a);
		Q.push({ a, 0 });
	}

	while (k) {
		long long a, d;
		tie(a, d) = Q.front();
		Q.pop();

		if (d > 0) {
			sum += d;
			k--;
		}

		if (!S.count(a - 1)) {
			S.insert(a - 1);
			Q.push({ a - 1, d + 1 });
		}

		if (!S.count(a + 1)) {
			S.insert(a + 1);
			Q.push({ a + 1, d + 1 });
		}
	}

	cout << sum;
}