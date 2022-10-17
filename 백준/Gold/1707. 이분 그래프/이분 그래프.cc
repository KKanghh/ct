#include<bits/stdc++.h>
using namespace std;
int vis[20001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	while (k--) {
		int v, e;
		cin >> v >> e;
		vector<int> adj[20001];
		fill(vis, vis + v + 1, 0);
		while (e--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool isBi = true;
		for (int i = 1; i <= v; i++) {
			if (vis[i] > 0) continue;
			Q.push(i);
			vis[i] = 1;
			while (!Q.empty()) {
				int t = Q.front();
				Q.pop();
				for (int e : adj[t]) {
					if (vis[e] == vis[t]) isBi = false;

					if (vis[e] > 0) continue;
					vis[e] = 3 - vis[t];
					Q.push(e);
				}
			}
		}
		
		if (isBi) cout << "YES\n";
		else cout << "NO\n";
	}
}