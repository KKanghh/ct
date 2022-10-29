#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001], result;
int deg[1001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int k;
		cin >> k;
		int a, b;
		cin >> a;
		k--;
		while (k--) {
			cin >> b;
			adj[a].push_back(b);
			deg[b]++;
			a = b;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) Q.push(i);
	}

	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		result.push_back(k);
		for (int nxt : adj[k]) {
			deg[nxt]--;
			if (deg[nxt] == 0) {
				Q.push(nxt);
			}
		}
	}

	if (result.size() != n) cout << 0;
	else {
		for (int e : result) cout << e << '\n';
	}
}