#include <bits/stdc++.h>
using namespace std;
int mx;
vector<pair<int, int>> adj[10001];
int dist[10001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; i++) {
		fill(dist + 1, dist + n + 1, -1);
		Q.push(i);
		dist[i] = 0;
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (auto e : adj[k]) {
				if (dist[e.first] >= 0) continue;
				dist[e.first] = dist[k] + e.second;
				Q.push(e.first);
			}
		}
		mx = max(mx, *max_element(dist + 1, dist + n + 1));
	}

	cout << mx;
}