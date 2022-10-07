#include <bits/stdc++.h>
using namespace std;
vector<int> V[101];
bool vis[101][101];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool t;
			cin >> t;
			if (t) V[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		Q.push(i);
		while (!Q.empty()) {
			int k = Q.front();
			Q.pop();
			for (int e : V[k]) {
				if (vis[i][e]) continue;
				vis[i][e] = true;
				Q.push(e);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << vis[i][j] << ' ';
		}
		cout << '\n';
	}
	
}