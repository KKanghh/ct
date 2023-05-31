#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[5001];
int dist[5001];
priority_queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({ b, d });
		adj[b].push_back({ a, d });
	}

	int s, t;
	cin >> s >> t;

	fill(dist + 1, dist + n + 1, 0x3f3f3f3f);
	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int d, a;
		tie(d, a) = pq.top();
		pq.pop();

		for (auto e : adj[a]) {
			if (dist[e.first] <= d + e.second) continue;
			dist[e.first] = d + e.second;
			pq.push({ dist[e.first], e.first });
		}
	}

	cout << dist[t];
}