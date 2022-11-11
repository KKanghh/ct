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

	int n, m;
	cin >> n >> m;

	m++;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, a, b });
	}

	fill(p, p + n + 1, -1);
	sort(edge.begin(), edge.end());

	int mn = 0, mx = 0, cnt = 0;

	for (int i = 0; i < edge.size(); i++) {
		int a, b, c;
		tie(a, b, c) = edge[i];
		if (find(b) == find(c)) continue;
		merge(b, c);
	
		if (a == 0) mx++;
		cnt++;
		if (cnt == n) break;
	}

	fill(p, p + n + 1, -1);
	cnt = 0;

	for (int i = edge.size() - 1; i >= 0; i--) {
		int a, b, c;
		tie(a, b, c) = edge[i];
		if (find(b) == find(c)) continue;
		merge(b, c);
		if (a == 0) mn++;
		cnt++;
		if (cnt == n) break;
	}

	cout << mx * mx - mn * mn;
}