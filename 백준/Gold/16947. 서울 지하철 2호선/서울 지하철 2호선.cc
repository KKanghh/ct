#include <bits/stdc++.h>
using namespace std;
vector<int> adj[3001];
int dist[3001];
bool loop;
int mn;

void dfs(int a, int b) {
	for (int e : adj[b]) {
		if (e == a) continue;

		if (dist[e] >= 0) {
			mn = min(mn, dist[e]);
		}
		else {
			dist[e] = dist[b] + 1;
			dfs(b, e);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		loop = false;
		mn = 0x7f7f7f7f;
		fill(dist, dist + n + 1, -1);
		dist[i] = 0;
		dfs(0, i);
		cout << mn << ' ';
	}
}