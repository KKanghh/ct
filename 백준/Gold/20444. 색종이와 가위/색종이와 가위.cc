#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n, k;
	cin >> n >> k;

	long long st = 0, en = n;

	while (st < en) {
		long long mid = (st + en) / 2;
		long long r = n - mid;

		if ((mid + 1) * (r + 1) < k) st = mid + 1;
		else en = mid;
	}

	long long r = n - st;
	if ((r + 1) * (st + 1) == k) cout << "YES";
	else cout << "NO";

}