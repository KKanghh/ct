#include <bits/stdc++.h>
using namespace std;
vector<int> adj[26];
bool vis[26];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		char a, b;
		string is;
		cin >> a >> is >> b;

		adj[a - 'a'].push_back(b - 'a');
	}

	int m;
	cin >> m;
	while (m--) {
		fill(vis, vis + 26, false);

		char a, b;
		string is;
		cin >> a >> is >> b;

		vis[a - 'a'] = true;
		Q.push(a - 'a');

		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();

			for (int e : adj[k]) {
				if (vis[e]) continue;
				vis[e] = true;
				Q.push(e);
			}
		}

		if (vis[b - 'a']) cout << "T\n";
		else cout << "F\n";

	}

}