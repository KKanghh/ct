#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> animals;
vector<int> sade;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, l;
	cin >> m >> n >> l;

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		sade.push_back(t);
	}

	sort(sade.begin(), sade.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		int t = lower_bound(sade.begin(), sade.end(), x) - sade.begin();
		int len = abs(x - sade[t]) + y;
		if (t > 0) len = min(len, abs(x - sade[t - 1]) + y);
		if (len <= l) cnt++;
	}

	cout << cnt;
}