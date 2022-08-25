#include <bits/stdc++.h>
using namespace std;

int LAN[10000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> LAN[i];

	long long st = 0, en = INT_MAX;

	while (st < en) {
		int mid = (st + en + 1) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) cnt += (LAN[i] / mid);

		if (cnt >= n) st = mid;
		else en = mid - 1;
	}

	cout << st;
}