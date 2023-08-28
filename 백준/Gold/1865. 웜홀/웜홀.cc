#include <bits/stdc++.h>
using namespace std;
int dist[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, m, w;
		cin >> n >> m >> w;

		for (int i = 1; i <= n; i++) fill(dist[i] + 1, dist[i] + n + 1, 0x3f3f3f3f);

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			dist[a][b] = min(dist[a][b], d);
			dist[b][a] = min(dist[b][a], d);
		}

		for (int i = 0; i < w; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			dist[a][b] = min(dist[a][b], -d);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		bool possible = false;
		for (int i = 1; i <= n; i++) {
			possible = possible || dist[i][i] < 0;
		}

		if (possible) cout << "YES\n";
		else cout << "NO\n";
	}
}