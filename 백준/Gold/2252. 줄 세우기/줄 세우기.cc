#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32005];
int deg[32005];
queue<int> Q;
vector<int> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!deg[i]) Q.push(i);
	}

	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		result.push_back(k);
		for (int e : adj[k]) {
			deg[e]--;
			if (!deg[e]) Q.push(e);
		}
	}

	for (int e : result) cout << e << ' ';
}