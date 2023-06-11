#include <bits/stdc++.h>
using namespace std;
long long d[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];
	long long m;
	cin >> m;

	long long st = 0, en = *max_element(d, d + n);

	while (st < en) {
		long long mid = (st + en + 1) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) cnt += min(d[i], mid);

		if (cnt <= m) st = mid;
		else en = mid - 1;
	}

	cout << st;
}