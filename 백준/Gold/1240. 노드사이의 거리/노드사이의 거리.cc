#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[1001];
int dist[1001][1001];
bool vis[1001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		adj[a].push_back({ b, l });
		adj[b].push_back({ a, l });
	}

	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, false);
		vis[i] = true;
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (auto e : adj[k]) {
				if (vis[e.first]) continue;
				dist[i][e.first] = dist[i][k] + e.second;
				vis[e.first] = true;
				Q.push(e.first);
			}
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}

}