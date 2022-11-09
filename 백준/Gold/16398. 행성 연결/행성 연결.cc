#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> edge;
int p[1001];

int find(int n) {
	if (p[n] < 0) return n;
	return p[n] = find(p[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (p[a] == p[b]) p[a]--;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	fill(p + 1, p + n + 1, -1);

	for (int i = 1; i <= n; i++) {
		int j = 1;
		for (; j < i; j++) {
			int c;
			cin >> c;
			edge.push_back({c, i ,j});
		}
		for (; j <= n; j++) {
			int c;
			cin >> c;
		}
	}

	sort(edge.begin(), edge.end());
	long long cost = 0, cnt = 0;

	for (int i = 0; i < edge.size(); i++) {
		int a, b, c;
		tie(a, b, c) = edge[i];

		if (find(b) == find(c)) continue;
		merge(b, c);
		cost += a;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << cost;
}