#include <bits/stdc++.h>
using namespace std;
bool know[51];
vector<int> party[50];
vector<int> adj[51];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int p;
	cin >> p;
	while (p--) {
		int t;
		cin >> t;
		Q.push(t);
	}

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int c;
			cin >> c;
			party[i].push_back(c);
		}
		for (int j = 0; j < t; j++) {
			adj[party[i][j]].push_back(i);
		}
	}

	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();

		for (int e : adj[k]) {
			if (know[e]) continue;
			know[e] = true;
			m--;
			for (int t : party[e]) Q.push(t);
		}
	}

	cout << m;
}