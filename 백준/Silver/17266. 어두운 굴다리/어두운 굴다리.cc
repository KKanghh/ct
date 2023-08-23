#include <bits/stdc++.h>
using namespace std;
vector<int> g;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	g.push_back(0);
	for (int i = 1; i <= m; i++) {
		int t;
		cin >> t;
		g.push_back(t);
	};
	g.push_back(n);

	int st = max(g[1], n - g[m]);
	int en = n;

	while (st < en) {
		int mid = (st + en) / 2;
		int cur = 1;
		for (; cur <= m; cur++) {
			if (g[cur] - mid > g[cur - 1] + mid || g[cur] + mid < g[cur + 1] - mid) break;
		}

		if (cur == m + 1) en = mid;
		else st = mid + 1;
	}

	cout << st;
}