#include <bits/stdc++.h>
using namespace std;
set<int> hongik;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	int cur = 1;

	for (int i = 1; i <= n; i++) {
		bool a;
		cin >> a;
		if (a) hongik.insert(i);
	}

	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i;
			cin >> i;
			if (hongik.count(i)) hongik.erase(i);
			else hongik.insert(i);
		}
		else if (c == 2) {
			int x;
			cin >> x;
			cur = (cur - 1 + x) % n + 1;
		}
		else {
			if (hongik.empty()) cout << -1 << '\n';
			else {
				auto it = hongik.lower_bound(cur);
				if (it == hongik.end()) {
					it = hongik.lower_bound(1);
					cout << n - (cur - *it) << '\n';
				}
				else cout << *it - cur << '\n';
			}
		}
	}

}