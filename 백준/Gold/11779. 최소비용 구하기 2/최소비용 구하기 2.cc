#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[1001], pre[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	fill(dist + 1, dist + n + 1, INF);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ c, b });
	}

	int s, d;
	cin >> s >> d;

	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (dist[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
				dist[nxt.Y] = dist[cur.Y] + nxt.X;
				pq.push({ dist[nxt.Y], nxt.Y });
				pre[nxt.Y] = cur.Y;
			}
		}
	}

	stack<int> S;
	cout << dist[d] << '\n';
	S.push(d);
	while (pre[d] != 0) {
		d = pre[d];
		S.push(d);
	}

	cout << S.size() << '\n';
	while (!S.empty()) {
		cout << S.top() << ' ';
		S.pop();
	}

}