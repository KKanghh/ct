#include <bits/stdc++.h>
using namespace std;
int D[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		fill(D, D + 100001, 0);
		int n;
		cin >> n;
		int k = 2;
		int cnt = 0;
		while (k * k <= n) {
			while (n % k == 0) {
				n /= k;
				D[k]++;
				cnt++;
			}
			k++;
		}
		if (n > 1) {
			cnt++;
			D[n]++;
		}

		int i = 0;
		while (cnt > 0) {
			if (D[i] > 0) {
				cnt -= D[i];
				cout << i << ' ' << D[i] << '\n';
			}
			i++;
		}
	}
}