#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool vis[501];
queue<pair<int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		fill(vis, vis + n + 1, false);

		vector<int> adj[501];
		int tree[501];
		fill(tree, tree + n + 1, 0);

		while (m--) {
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			bool isTree = true;
			Q.push({ 0, i });
			vis[i] = true;
			while (!Q.empty()) {
				int a, b;
				tie(a, b) = Q.front();
				Q.pop();
				for (int e : adj[b]) {
					if (e == a) continue;
					if (vis[e]) {
						isTree = false;
						continue;
					}
					vis[e] = true;
					Q.push({ b, e });
				}
			}
			cnt += isTree;
		}

		cout << "Case " << t++ << ": ";
		if (cnt == 0) cout << "No trees.\n";
		else if (cnt == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << cnt << " trees.\n";
	}
}