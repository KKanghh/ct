#include <bits/stdc++.h>
using namespace std;
vector<int> heavy[100], light[100];
bool vis[100], impossible[100];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;

		light[a].push_back(b);
		heavy[b].push_back(a);
	}

	int cnt;

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		if (impossible[i]) continue;
		fill(vis, vis + n + 1, false);
		vis[i] = true;
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : heavy[k]) {
				if (vis[e]) continue;
				cnt++;
				vis[e] = true;
				Q.push(e);
			}
		}
		if (cnt > n / 2) impossible[i] = true;
	}

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		if (impossible[i]) continue;
		fill(vis, vis + n + 1, false);
		vis[i] = true;
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : light[k]) {
				if (vis[e]) continue;
				vis[e] = true;
				cnt++;
				Q.push(e);
			}
		}
		if (cnt > n / 2) impossible[i] = true;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (impossible[i]) ans++;
	}

	cout << ans;
}