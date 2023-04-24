#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[50001];
int dist[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b, d;
		cin >> a >> b >> d;

		adj[a].push_back({ d, b});
		adj[b].push_back({ d, a });
	}

	fill(dist, dist + n + 1, 0x3f3f3f3f);

	dist[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (dist[b] != a) continue;

		for (auto k : adj[b]) {
			if (a + k.first >= dist[k.second]) continue;

			dist[k.second] = dist[b] + k.first;
			pq.push({ dist[k.second], k.second });
		}
	}

	cout << dist[n];

}