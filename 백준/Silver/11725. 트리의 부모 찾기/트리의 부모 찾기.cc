#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int p[100001];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;


	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	Q.push(1);
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int e : adj[k]) {
			if (e == 1 || p[e]) continue;
			p[e] = k;
			Q.push(e);
		}
	}

	for (int i = 2; i <= n; i++) cout << p[i] << '\n';


}