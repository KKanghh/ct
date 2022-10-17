#include <bits/stdc++.h>
using namespace std;
int board[1001];
bool vis[1001], link[1001][1001];
queue<int> Q;
stack<int> S;
int N, M, V;

int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		link[a][b] = true;
		link[b][a] = true;
	}

	S.push(V);
	while (!S.empty()) {
		int t = S.top();
		S.pop();
		if (vis[t]) continue;
		cout << t << ' ';
		vis[t] = true;
		for (int i = N; i > 0; i--) {
			if (!link[t][i] || vis[i]) continue;
			S.push(i);
		}
	}
	cout << '\n';

	fill(vis, vis + N + 1, false);
	vis[V] = true;
	Q.push(V);
	while (!Q.empty()) {
		int t = Q.front();
		cout << t << ' ';
		Q.pop();
		for (int i = 1; i <= N; i++) {
			if (!link[t][i] || vis[i]) continue;
			vis[i] = true;
			Q.push(i);
		}
	}
}
