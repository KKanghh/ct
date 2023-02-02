#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k = 9, cnt = 0;

		if (n < 10) {
			cout << 1 << '\n';
			continue;
		}

		while (k > 1) {
			while (n % k == 0) {
				n /= k;
				cnt++;
			}
			k--;
		}

		if (k == 1 && n > 9) cout << -1; 
		else cout << cnt;
		cout << '\n';
	}
	
}