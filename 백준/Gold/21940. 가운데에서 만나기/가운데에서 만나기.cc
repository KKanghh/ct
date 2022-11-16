#include <bits/stdc++.h>
using namespace std;
int dist[201][201];
const int INF = 0x3f3f3f3f;
vector<int> friends;

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
		int a, b, t;
		cin >> a >> b >> t;

		if (dist[a][b] > t) dist[a][b] = t;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int i;
		cin >> i;
		friends.push_back(i);
	}

	int mn = 0x7f7f7f7f;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int e : friends) {
			if (dist[e][i] == INF) {
				mx = 0x7f7f7f7f;
				break;
			}
			mx = max(dist[e][i] + dist[i][e], mx);
		}

		if (mx == mn) {
			ans.push_back(i);
		}
		else if (mx < mn) {
			mn = mx;
			vector<int> temp;
			temp.push_back(i);
			ans = temp;
		}
	}

	for (int e : ans) cout << e << ' ';
}