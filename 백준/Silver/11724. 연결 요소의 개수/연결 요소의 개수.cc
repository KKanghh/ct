#include <bits/stdc++.h>
using namespace std;
vector<int> V[1001];
int team[1001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;

		V[a].push_back(b);
		V[b].push_back(a);
	}
	int p = 0;
	fill(team, team + n + 1, -1);

	for (int i = 1; i <= n; i++) {
		if (team[i] != -1) continue;
		Q.push(i);
		team[i] = ++p;
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : V[k]) {
				if (team[e] != -1) continue;
				team[e] = team[i];
				Q.push(e);
			}
		}
	}

	cout << p;
}