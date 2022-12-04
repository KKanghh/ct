#include <bits/stdc++.h>
using namespace std;
vector<pair<unsigned long long, int>> adj[100001];
unsigned long long s[100001], dist[100001];
priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<unsigned long long, int>>> pq;
const unsigned long long INF = 0xffffffffffffffff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	unsigned long long c;
	cin >> n >> m >> a >> b >> c;
	fill(dist + 1, dist + n + 1, INF);
	fill(s + 1, s + n + 1, INF);
	while (m--) {
		int u, v;
		unsigned long long k;
		cin >> u >> v >> k;
		adj[u].push_back({ k, v });
		adj[v].push_back({ k, u });
	}
	s[a] = 0;
	dist[a] = 0;
	pq.push({ 0, a });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.first > dist[cur.second]) continue;
		for (auto nxt : adj[cur.second]) {
			if (dist[cur.second] + nxt.first > c) continue;
			unsigned long long mx = max(s[cur.second], nxt.first);
			if (mx >= s[nxt.second]) continue;
			dist[nxt.second] = dist[cur.second] + nxt.first;
			s[nxt.second] = mx;

			pq.push({ dist[nxt.second], nxt.second });
		}
	}
	if (dist[b] == INF) cout << -1;
	else cout << s[b];

}