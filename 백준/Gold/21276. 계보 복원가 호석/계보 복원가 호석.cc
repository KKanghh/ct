#include <bits/stdc++.h>
using namespace std;
map<string, int> deg;
map<string, vector<string>> adj;
map<string, vector<string>> children;
queue<string> Q;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		deg[name] = 0;
		vector<string> temp;
		children[name] = temp;
	}

	int m;
	cin >> m;
	while (m--) {
		string a, b;
		cin >> a >> b;
		deg[a]++;
		adj[b].push_back(a);
	}

	for (pair<string, int> e : deg) {
		if (e.second == 0) Q.push(e.first);
	}
	int k = Q.size();
	cout << k << '\n';

	while (!Q.empty()) {
		string name = Q.front();
		Q.pop();
		if (k-- > 0) cout << name << ' ';
		for (string e : adj[name]) {
			deg[e]--;
			if (deg[e] == 0) {
				children[name].push_back(e);
				Q.push(e);
			}
		}
	}
	cout << '\n';

	for (pair<string, vector<string>> e : children) {
		cout << e.first << ' ' << e.second.size() << ' ';
		sort(e.second.begin(), e.second.end());
		for (string name : e.second) cout << name << ' ';
		cout << '\n';
	}
}