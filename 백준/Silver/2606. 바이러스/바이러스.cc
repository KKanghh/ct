#include <bits/stdc++.h>
using namespace std;
vector<int> com[101];
bool vis[101];
queue<int> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}
	int cnt = 0;
	Q.push(1);
	vis[1] = true;
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int e : com[k]) {
			if (vis[e]) continue;
			vis[e] = true;
			Q.push(e);
			cnt++;
		}
	}

	cout << cnt;

}