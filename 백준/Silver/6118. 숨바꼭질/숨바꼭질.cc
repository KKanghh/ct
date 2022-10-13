#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20001];
int dist[20001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(dist, dist + 20001, -1);
	dist[1] = 0;
	Q.push(1);
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int e : adj[k]) {
			if (dist[e] > -1) continue;
			dist[e] = dist[k] + 1;
			Q.push(e);
		}
	}

	int ans = 0, cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (dist[i] > dist[ans]) {
			ans = i;
			cnt = 1;
		}
		else if (dist[i] == dist[ans]) cnt++;
	}

	cout << ans << ' ' << dist[ans] << ' ' << cnt;
}