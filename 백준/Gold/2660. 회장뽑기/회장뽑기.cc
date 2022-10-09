#include <bits/stdc++.h>
using namespace std;
int score[51], vis[51];
vector<int> adj[51];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, -1);
		vis[i] = 0;
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : adj[k]) {
				if (vis[e] > -1) continue;
				vis[e] = vis[k] + 1;
				Q.push(e);
			}
		}

		int s = 0;

		for (int j = 1; j <= n; j++) {
			s = max(s, vis[j]);
		}
		score[i] = s;
	}

	int k = *min_element(score + 1, score + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (score[i] == k) cnt++;
	}

	cout << k << ' ' << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (score[i] == k) cout << i << ' ';
	}
}