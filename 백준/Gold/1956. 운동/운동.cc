#include <bits/stdc++.h>
using namespace std;

int dist[401][401];
const int INF = 0x3f3f3f3f;
vector<int> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		fill(dist[i] + 1, dist[i] + v + 1, INF);
	}

	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int i = 1; i <= v; i++) {
		V.push_back(i);
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}


	int mn = INF;

	for (int i = 1; i <= v; i++) {
		mn = min(dist[i][i], mn);
	}

	if (mn == INF) cout << -1;
	else cout << mn;
}