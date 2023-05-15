#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> V[200001];
queue<pair<int, int>> Q;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, T;

	cin >> n >> T;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		V[b].push_back({ a, -1 });
	}

	V[0].push_back({ 0, 0 });
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop();
		int k = 0;
		for (auto e : V[y]) {
			if (e.first == x) k = e.second;
		}

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				int nx = x + i;
				int ny = y + j;

				if (nx < 0 || nx > 1e6 || ny < 0 || ny > T) continue;
				for (int a = 0; a < V[ny].size(); a++) {
					if (V[ny][a].first == nx && V[ny][a].second == -1) {
						V[ny][a].second = k + 1;
						Q.push({ nx, ny });
					}
				}
			}
		}
	}

	int mn = INT_MAX;
	for (auto e : V[T]) {
		if (e.second == -1) continue;
		mn = min(mn, e.second);
	}

	if (mn == INT_MAX) cout << -1;
	else cout << mn;
}