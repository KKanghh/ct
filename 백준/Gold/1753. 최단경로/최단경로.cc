#include <bits/stdc++.h>
using namespace std;
int dist[20001];
vector<pair<int, int>> adj[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	int k;
	cin >> k;
	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	fill(dist + 1, dist + v + 1, INF);

	dist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int d, e;
		tie(d, e) = pq.top();
		pq.pop();
		if (dist[e] != d) continue;
		for (auto a : adj[e]) {
			if (dist[a.first] > dist[e] + a.second) {
				dist[a.first] = dist[e] + a.second;
				pq.push({ dist[a.first], a.first });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}