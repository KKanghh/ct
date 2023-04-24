#include <bits/stdc++.h>
using namespace std;

bool visible[100000];
vector<pair<int, int>> adj[100000];
long long dist[100000];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> visible[i];

	while (m--) {
		int a, b, t;
		cin >> a >> b >> t;

		adj[a].push_back({ t, b });
		adj[b].push_back({ t, a });
	}

	fill(dist, dist + n, LLONG_MAX);

	dist[0] = 0;
	pq.push({ dist[0], 0 });

	while (!pq.empty()) {
		long long a, b;
		tie(a, b) = pq.top();
		pq.pop();

		if (dist[b] != a) continue;

		for (auto nxt : adj[b]) {
			if (a + nxt.first >= dist[nxt.second]) continue;
			if (visible[nxt.second] && nxt.second != n - 1) continue;

			dist[nxt.second] = a + nxt.first;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}

	if (dist[n - 1] == LLONG_MAX) cout << -1;
	else cout << dist[n - 1];
}