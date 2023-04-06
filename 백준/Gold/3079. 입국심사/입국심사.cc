#include <bits/stdc++.h>
using namespace std;
long long T[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> T[i];
	}

	long long st = 1, en = 1000000000000000000;

	while (st < en) {
		long long cnt = 0;
		long long md = (st + en) / 2;

		for (int i = 0; i < n; i++) {
			cnt += md / T[i];
			if (cnt > m) break;
		}

		if (cnt < m) st = md + 1;
		else en = md;

	}

	cout << st;
}