#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[1001];
int dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
  }

  fill(dist + 1, dist + n + 1, 0x3f3f3f3f);

  int from, to;
  cin >> from >> to;

  dist[from] = 0;
  pq.push({0, from});

  while (!pq.empty()) {
    int a, b;
    tie(a, b) = pq.top();
    pq.pop();

    if (a > dist[b]) continue;

    for (auto e: adj[b]) {
      if (a + e.second >= dist[e.first]) continue;
      dist[e.first] = a + e.second;
      pq.push({dist[e.first], e.first});
    }
  }
  cout << dist[to];
}