#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51], party[51];
vector<int> truth;
bool know[51];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	int trunum;
	cin >> trunum;
	while (trunum--) {
		int k;
		cin >> k;
		truth.push_back(k);
	}

	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		k--;
		int a, b;
		cin >> a;
		party[i].push_back(a);
		while (k--) {
			cin >> b;
			party[i].push_back(b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	for (int k : truth) {
		know[k] = true;
		Q.push(k);

		while (!Q.empty()) {
			int t = Q.front();
			Q.pop();
			for (int e : adj[t]) {
				if (know[e]) continue;
				know[e] = true;
				Q.push(e);
			}
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		cnt++;
		for (int e : party[i]) {
			if (know[e]) {
				cnt--;
				break;
			}
		}
	}
	cout << cnt;
}