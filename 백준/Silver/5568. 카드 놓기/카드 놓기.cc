#include <bits/stdc++.h>
using namespace std;
int num[10];
bool vis[10];
int n, k;
int t;
unordered_set<int> S;

void dfs(int a) {
	if (a == k) {
		S.insert(t);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		int b = num[i];
		while (b > 0) {
			t = t * 10 + b % 10;
			b /= 10;
		}
		dfs(a + 1);
		int c = num[i];
		while (c > 0) {
			t /= 10;
			c /= 10;
		}
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> num[i];

	dfs(0);

	cout << S.size();
}