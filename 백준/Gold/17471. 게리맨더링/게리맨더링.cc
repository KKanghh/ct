#include <bits/stdc++.h>
using namespace std;
vector<int> adj[11];
int ingu[11];

bool check(vector<int> V) {
	if (V.size() == 0) return false;
	bool vis[11] = { false };
	bool team[11] = { false };
	for (int v : V) team[v] = true;
	queue<int> Q;
	Q.push(V[0]);
	vis[V[0]] = true;
	while (!Q.empty()) {
		int k = Q.front();
		Q.pop();
		for (int e : adj[k]) {
			if (!team[e] || vis[e]) continue;
			vis[e] = true;
			Q.push(e);
		}
	}

	for (int e : V) {
		if (!vis[e]) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int mn = 0x3f3f3f3f;

	for (int i = 1; i <= n; i++) cin >> ingu[i];
	for (int i = 1; i <= n; i++) {
		int j;
		cin >> j;
		while (j--) {
			int k;
			cin >> k;
			adj[i].push_back(k);
		}
	}

	int cases = 1;
	for (int i = 0; i < n; i++) cases *= 2;

	for (int i = 0; i < cases; i++) {
		vector<int> A, B;
		int t = i;
		for (int j = 1; j <= n; j++) {
			if (t % 2 == 1) A.push_back(j);
			else B.push_back(j);

			t /= 2;
		}
		
		if (!check(A) || !check(B)) continue;

		int A_cnt = 0;
		int B_cnt = 0;
		for (int e : A) A_cnt += ingu[e];
		for (int e : B) B_cnt += ingu[e];

		mn = min(mn, abs(A_cnt - B_cnt));
	}

	if (mn == 0x3f3f3f3f) cout << -1;
	else cout << mn;
}