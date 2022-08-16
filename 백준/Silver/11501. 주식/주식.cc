#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
stack<pair<int, int>> S;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long cnt = 0;
		S.push({ 10001, 0 });
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			if (tmp < S.top().X) {
				S.push({ tmp, i });
			}
			else {
				while (S.top().X <= tmp) {
					int a, b;
					tie(a, b) = S.top();
					S.pop();
					cnt += (tmp - a) * (b - S.top().Y);
				}
				S.push({ tmp, i });
			}
		}

		cout << cnt << '\n';
	}
}