#include <bits/stdc++.h>
using namespace std;

int d[1000000];

int find(int n) {
	if (d[n] < 0) return n;
	return d[n] = find(d[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (d[a] == d[b]) d[a]--;
	if (d[a] < d[b]) d[b] = a;
	else d[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, k;
		cin >> n >> k;

		fill(d, d + n, -1);

		while (k--) {
			int a, b;
			cin >> a >> b;
			if (find(a) != find(b)) merge(a, b);
		}
		cout << "Scenario " << i << ":\n";
		int m;
		cin >> m;
		while (m--) {
			int u, v;
			cin >> u >> v;
			bool result = find(u) == find(v);
			cout << result << '\n';
		}
		cout << '\n';
	}
}