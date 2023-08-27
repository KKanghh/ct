#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
set<int> S;
set<int> adj[201];

void dfs(int k) {
	if (S.size() == 3) {
		cnt++;
		return;
	}

	for (int i = k; i <= n; i++) {
		bool cant = false;
		for (int e: S) {
			cant = cant || adj[e].count(i);
		}
		if (cant) continue;
		S.insert(i);
		dfs(i + 1);
		S.erase(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].insert(b);
		adj[b].insert(a);
	}

	dfs(1);

	cout << cnt;
}