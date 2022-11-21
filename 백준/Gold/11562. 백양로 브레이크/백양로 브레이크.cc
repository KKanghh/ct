#include <bits/stdc++.h>
using namespace std;
int dist[251][251];
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(dist[i] + 1, dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
	while (m--) {
		int u, v;
		bool b;
		cin >> u >> v >> b;
		if (b) {
			dist[u][v] = 0;
			dist[v][u] = 0;
		}
		else {
			dist[u][v] = 0;
			dist[v][u] = 1;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int k;
	cin >> k;

	while (k--) {
		int s, e;
		cin >> s >> e;

		cout << dist[s][e] << '\n';
	}

}