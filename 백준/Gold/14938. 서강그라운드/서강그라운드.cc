#include <bits/stdc++.h>
using namespace std;

int dist[101][101], item[101];
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
		fill(dist[i] + 1, dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}

	while (r--) {
		int a, b, l;
		cin >> a >> b >> l;
		if (dist[a][b] > l) {
			dist[a][b] = l;
			dist[b][a] = l;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	int cnt = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) {
				cnt += item[j];
			}
		}
		mx = max(mx, cnt);
	}

	cout << mx;

}