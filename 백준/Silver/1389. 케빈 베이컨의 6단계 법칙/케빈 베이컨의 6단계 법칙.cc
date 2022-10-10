#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101];
int kb[101], dist[101];
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

	for (int i = 1; i <= n; i++) {
		fill(dist, dist + n + 1, -1);
		dist[i] = 0;
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : adj[k]) {
				if (dist[e] >= 0) continue;
				dist[e] = dist[k] + 1;
				Q.push(e);
			}
		}
		for (int j = 1; j <= n; j++) kb[i] += dist[j];
	}

	int ans = 0, value = 0x7fffffff;

	for (int i = 1; i <= n; i++) {
		if (kb[i] < value) {
			value = kb[i];
			ans = i;
		}
	}

	cout << ans;

}