#include <bits/stdc++.h>
using namespace std;

int d[1001];
deque<tuple<int, int, int>> edge;
unordered_set<int> X;

int find(int x) {
	if (d[x] < 0) return x;
	else return d[x] = find(d[x]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);

	if (d[x] == d[y]) d[x]--;
	if (d[y] < d[x]) swap(x, y);
	d[y] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		edge.push_back({ i, a, b });
	}

	while (k--) {
		fill(d, d + n + 1, -1);
		int cnt = 0, point = 0;
		for (int i = 0; i < edge.size(); i++) {
			int l, a, b;
			tie(l, a, b) = edge[i];

			if (find(a) == find(b)) continue;
			merge(a, b);
			cnt++;
			point += l;
			if (cnt == n - 1) break;
		}
		if (cnt == n - 1) {
			cout << point << ' ';
			edge.pop_front();
		}
		else cout << 0 << ' ';
	}
}