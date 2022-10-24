#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int parent[100005], child[100005];
queue<int> Q;

void dfs(int n) {
	for (int e : adj[n]) {
		if (parent[e] > -1) continue;
		parent[e] = n;
		dfs(e);
		child[n] += child[e];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(parent, parent + n + 1, -1);
	fill(child, child + n + 1, 1);
	parent[r] = 0;
	dfs(r);
	
	while (q--) {
		int k;
		cin >> k;
		cout << child[k] << '\n';
	}

	
}