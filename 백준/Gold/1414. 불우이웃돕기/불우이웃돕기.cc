#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> adj[50];
bool vis[50];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int total = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			int score = 0;
			if (s[j] == '0') continue;
			if (s[j] >= 'a') score = s[j] - 'a' + 1;
			else score = s[j] - 'A' + 27;
			total += score;
			if (i == j) continue;

			adj[i].push_back({ score, j });
			adj[j].push_back({ score, i });


		}
	}

	int mn = 0, cnt = 0;

	vis[0] = true;
	for (auto k : adj[0]) {
		pq.push({ k.first, k.second });
	}

	while (!pq.empty()) {
		int cur, dist;
		tie(dist, cur) = pq.top();
		pq.pop();

		if (vis[cur]) continue;

		vis[cur] = true;
		mn += dist;
		cnt++;
		if (cnt == n - 1) break;

		for (auto k : adj[cur]) {
			if (vis[k.second]) continue;
			pq.push({ k.first, k.second });
		}
	}

	if (cnt == n - 1) cout << total - mn;
	else cout << -1;
}