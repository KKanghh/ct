#include <bits/stdc++.h>
using namespace std;
int deg[32005];
vector<int> adj[32005], result;
priority_queue<int, vector<int>, greater<int>> Q;


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
		if (deg[i] == 0) Q.push(i);
	}

	while (!Q.empty()) {
		int k = Q.top();
		result.push_back(k);
		Q.pop();
		for (int e : adj[k]) {
			deg[e]--;
			if (deg[e] == 0) Q.push(e);
		}
	}

	for (int e : result) cout << e << ' ';
}