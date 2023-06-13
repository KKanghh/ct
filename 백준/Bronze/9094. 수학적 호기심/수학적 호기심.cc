#include <bits/stdc++.h>
using namespace std;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cnt = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((i * i + j * j + m) % (i * j) == 0) cnt++;
			}
		}

		cout << cnt << '\n';
	}
}