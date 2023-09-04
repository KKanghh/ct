#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k;
	cin >> k;

	int st = 1, en = 1e9;

	while (st < en) {
		int mid = (st + en) / 2;
		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += min(n, mid / i);
		}

		if (cnt >= k) en = mid;
		else st = mid + 1;
	}

	cout << st;
}