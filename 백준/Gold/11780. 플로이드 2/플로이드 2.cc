#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int dist[101][101], nxt[101][101];

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
		int a, b, c;
		cin >> a >> b >> c;
		if (dist[a][b] > c) {
			dist[a][b] = c;
		}
		nxt[a][b] = b;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) dist[i][j] = 0;
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k = i;
			if (dist[i][j] == 0) {
				cout << 0 << '\n';
				continue;
			}
			vector<int> path;
			while (nxt[k][j] != 0) {
				path.push_back(k);
				k = nxt[k][j];
			}
			path.push_back(k);
			cout << path.size() << ' ';
			for (int e : path) cout << e << ' ';
			cout << '\n';
		}
	}
}