#include <bits/stdc++.h>
using namespace std;
int L[1000], R[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n ; i++) cin >> L[i] >> R[i];

	int st = 0, en = 0;
	int mn = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		st = max(st, L[i]);
		en = max(en, R[i]);
		mn += L[i];
		mx += R[i];
	}

	if (mn > t || mx < t) {
		cout << -1;
		return 0;
	}

	while (st < en) {
		int mid = (st + en) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += min(R[i], mid);
		}

		if (sum < t) st = mid + 1;
		else en = mid;
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(R[i], st);
	}

	if (sum >= t) cout << st;
	else cout << -1;
}