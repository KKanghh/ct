#include <bits/stdc++.h>
using namespace std;
tuple<int, int, int> edge[100000];
int adj[10001];

int find(int a) {
	if (adj[a] < 0) return a;
	return adj[a] = find(adj[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (adj[a] > adj[b]) adj[b] = a;
	else adj[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	fill(adj + 1, adj + v + 1, -1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { c, a, b };
	}

	int weight = 0;
	int cnt = 0;

	sort(edge, edge + e);

	for (int i = 0; i < e; i++) {
		int a, b, c;
		tie(c, a, b) = edge[i];
		if (find(a) == find(b)) continue;
		merge(a, b);
		weight += c;
		cnt++;
		if (cnt == v - 1) break;
	}

	cout << weight;
}