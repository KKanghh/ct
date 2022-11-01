#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];
int cnt;

void dfs(int a, int b) {
	for (int e : adj[b]) {
		if (e == a) continue;
		if (vis[e]) {
			cnt++;
			continue;
		}
		vis[e] = true;
		dfs(b, e);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int tree = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(0, i);
			tree++;
		}
	}

	cout << tree - 1 + cnt / 2;
}