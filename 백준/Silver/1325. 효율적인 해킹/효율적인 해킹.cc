#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10001];
int cnt[10001];
bool vis[10001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, false);
		vis[i] = true;
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : adj[k]) {
				if (vis[e]) continue;
				vis[e] = true;
				cnt[i]++;
				Q.push(e);
			}
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) mx = max(mx, cnt[i]);
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == mx) cout << i << ' ';
	}
}