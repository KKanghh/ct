#include <bits/stdc++.h>
using namespace std;
int dist[201][201], nxt[201][201];
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
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
		nxt[a][b] = b;
		nxt[b][a] = a;
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
			if (nxt[i][j] == 0) cout << '-' << ' ';
			else cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}
}