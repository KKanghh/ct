#include <bits/stdc++.h>
using namespace std;
int lec[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> lec[i];

	long long st = *max_element(lec, lec + n), en = 1e9;

	while (st < en) {
		long long mid = (st + en) / 2;
		long long cnt = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			if (sum + lec[i] > mid) {
				if (sum > 0) cnt++;
				sum = lec[i];
			}
			else sum += lec[i];
		}
		cnt++;

		if (cnt > k) st = mid + 1;
		else en = mid;
	}

	cout << st;
}