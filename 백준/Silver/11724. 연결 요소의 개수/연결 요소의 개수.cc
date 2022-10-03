#include <bits/stdc++.h>
using namespace std;
vector<int> V[1001];
bool vis[1001];
queue<int> Q;

void func(int a) {
	for (int e : V[a]) {
		if (vis[e]) continue;
		vis[e] = true;
		func(e);
	}
}

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
	fill(vis, vis + n + 1, false);

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		p++;
		func(i);
	}

	cout << p;
}