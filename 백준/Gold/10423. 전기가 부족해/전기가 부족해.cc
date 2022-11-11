#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> edge;
int p[1001];

int find(int n) {
	if (p[n] < 0) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	int cnt = k - 1;
	fill(p, p + n + 1, -1);

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		merge(a, 0);
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({ w, u, v });
	}

	sort(edge.begin(), edge.end());

	int cur = 0;
	int cost = 0;

	while (cnt < n - 1) {
		int u, v, w;
		tie(w, u, v) = edge[cur++];
		if (find(u) == find(v)) continue;
		merge(u, v);
		cost += w;
		cnt++;
	}

	cout << cost;
}