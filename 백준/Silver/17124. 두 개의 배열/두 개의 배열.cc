#include <bits/stdc++.h>
using namespace std;

int A[1000000], B[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		long long sum = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++) cin >> A[i];
		for (int i = 0; i < m; i++) cin >> B[i];

		sort(B, B + m);

		for (int i = 0; i < n; i++) {
			int cur = lower_bound(B, B + m, A[i]) - B;
			int prev = cur - 1;
			if (cur == m) sum += B[prev];
			else if (cur == 0) sum += B[cur];
			else {
				if (abs(A[i] - B[prev]) <= abs(A[i] - B[cur])) sum += B[prev];
				else sum += B[cur];
			}
		}

		cout << sum << '\n';
	}
}