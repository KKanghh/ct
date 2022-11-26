#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector<pair<int, int>> adj[801];
const int INF = 0x3f3f3f3f;
int distA[801], distB[801], distC[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, e;
	cin >> n >> e;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	int u, v;
	cin >> u >> v;
	fill(distA + 1, distA + n + 1, INF);

	distA[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.X != distA[cur.Y]) continue;
		for (auto nxt : adj[cur.Y]) {
			if (cur.X + nxt.X < distA[nxt.Y]) {
				distA[nxt.Y] = cur.X + nxt.X;
				pq.push({ distA[nxt.Y], nxt.Y });
			}
		}
	}

	if (distA[u] == INF || distA[v] == INF || distA[n] == INF) {
		cout << -1;
		return 0;
	}

	fill(distB + 1, distB + n + 1, INF);

	distB[u] = 0;
	pq.push({ 0, u });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.X != distB[cur.Y]) continue;
		for (auto nxt : adj[cur.Y]) {
			if (cur.X + nxt.X < distB[nxt.Y]) {
				distB[nxt.Y] = cur.X + nxt.X;
				pq.push({ distB[nxt.Y], nxt.Y });
			}
		}
	}

	fill(distC + 1, distC + n + 1, INF);

	distC[v] = 0;
	pq.push({ 0, v });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (cur.X != distC[cur.Y]) continue;
		for (auto nxt : adj[cur.Y]) {
			if (cur.X + nxt.X < distC[nxt.Y]) {
				distC[nxt.Y] = cur.X + nxt.X;
				pq.push({ distC[nxt.Y], nxt.Y });
			}
		}
	}

	cout << min(distA[u] + distC[n], distA[v] + distB[n]) + distB[v];

}