#include <bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
int dist[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(dist[i] + 1, dist[i] + n + 1, INF);
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dist[a][b] > c) {
			dist[a][b] = c;
		}
	}

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) dist[j][k] = dist[j][i] + dist[i][k];
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
}