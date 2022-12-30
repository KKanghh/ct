#include <bits/stdc++.h>
using namespace std;
int house[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m, k, cnt = 0, v = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			cin >> house[i];
		}
		
		for (int i = 0; i < m; i++) v += house[i];

		if (n == m) {
			cout << (v < k)<< '\n';
			continue;
		}
		
		for (int i = 0; i < n; i++) {
			v -= house[i];
			v += house[(i + m) % n];
			if (v < k) cnt++;
		}

		cout << cnt << '\n';

	}
}