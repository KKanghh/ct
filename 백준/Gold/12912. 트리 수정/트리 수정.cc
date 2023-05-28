#include <bits/stdc++.h>
using namespace std;
vector<pair<int, long long>> adj[2000];
long long dist[2000];
queue<int> Q;
long long mx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back({ b, d });
		adj[b].push_back({ a, d });
	}

	for (int i = 0; i < n; i++) {
		for (auto e : adj[i]) {
			int j = e.first;
			long long d = e.second;

			fill(dist, dist + n, -1);

			dist[i] = 0;
			Q.push(i);
			while (!Q.empty()) {
				int k = Q.front();
				Q.pop();

				for (auto w : adj[k]) {
					if (w.first == j || dist[w.first] >= 0) continue;
					dist[w.first] = dist[k] + w.second;
					Q.push(w.first);
				}
			}

			int p = max_element(dist, dist + n) - dist;
			fill(dist, dist + n, -1);

			dist[p] = 0;
			Q.push(p);
			while (!Q.empty()) {
				int k = Q.front();
				Q.pop();

				for (auto w : adj[k]) {
					if (w.first == j || dist[w.first] >= 0) continue;
					dist[w.first] = dist[k] + w.second;
					Q.push(w.first);
				}
			}

			long long mx1 = *max_element(dist, dist + n);


			fill(dist, dist + n, -1);

			dist[j] = 0;
			Q.push(j);
			while (!Q.empty()) {
				int k = Q.front();
				Q.pop();

				for (auto w : adj[k]) {
					if (w.first == i || dist[w.first] >= 0) continue;
					dist[w.first] = dist[k] + w.second;
					Q.push(w.first);
				}
			}

			p = max_element(dist, dist + n) - dist;
			fill(dist, dist + n, -1);

			dist[p] = 0;
			Q.push(p);
			while (!Q.empty()) {
				int k = Q.front();
				Q.pop();

				for (auto w : adj[k]) {
					if (w.first == i || dist[w.first] >= 0) continue;
					dist[w.first] = dist[k] + w.second;
					Q.push(w.first);
				}
			}

			long long mx2 = *max_element(dist, dist + n);

			mx = max(mx, mx1 + d + mx2);
		}
	}

	cout << mx;
}