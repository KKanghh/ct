#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjin[1001], adjout[1001];
int distin[1001], distout[1001], dist[1001];
const int INF = 0x3f3f3f3f;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adjout[a].push_back({ c, b });
		adjin[b].push_back({ c, a });
	}

	fill(distin + 1, distin + n + 1, INF);
	fill(distout + 1, distout + n + 1, INF);
	distin[x] = 0;
	distout[x] = 0;
	pq.push({ 0, x });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (distin[cur.second] != cur.first) continue;
		for (auto nxt : adjin[cur.second]) {
			if (distin[nxt.second] > distin[cur.second] + nxt.first) {
				distin[nxt.second] = distin[cur.second] + nxt.first;
				pq.push({ distin[nxt.second], nxt.second});
			}
		}
	}
	pq.push({ 0, x });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (distout[cur.second] != cur.first) continue;
		for (auto nxt : adjout[cur.second]) {
			if (distout[nxt.second] > distout[cur.second] + nxt.first) {
				distout[nxt.second] = distout[cur.second] + nxt.first;
				pq.push({ distout[nxt.second], nxt.second });
			}
		}
	}

	for (int i = 1; i <= n; i++) dist[i] = distin[i] + distout[i];
	cout << *max_element(dist + 1, dist + n + 1);

}