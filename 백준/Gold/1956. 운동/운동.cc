#include <bits/stdc++.h>
using namespace std;
int dist[401][401];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) fill(dist[i] + 1, dist[i] + v + 1, 0x3f3f3f3f);

	for (int i = 0; i < e; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		dist[a][b] = d;
	}


	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int mn = 0x3f3f3f3f;

	for (int i = 1; i <= v; i++) {
		mn = min(mn, dist[i][i]);
	}

	if (mn == 0x3f3f3f3f) cout << -1;
	else cout << mn;

}