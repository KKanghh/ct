#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[301];
int w[301];
bool visited[301];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cost = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p;
			cin >> p;
			if (p == 0) continue;
			adj[i].push_back({min(w[j], p), j});
		}
	}
	
	int st = min_element(w + 1, w + n + 1) - w;
	cost += w[st];

	visited[st] = true;
	for (auto e : adj[st]) {
		Q.push({ e.first, e.second });
	}

	while (!Q.empty()) {
		int a, b;
		tie(a, b) = Q.top();
		Q.pop();
		if (visited[b]) continue;
		visited[b] = true;
		cost += a;
		for (auto e : adj[b]) {
			if (visited[e.second]) continue;
			Q.push({ e.first, e.second });
		}
	}

	cout << cost;
}