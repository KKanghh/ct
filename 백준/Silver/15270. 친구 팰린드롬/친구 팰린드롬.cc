#include <bits/stdc++.h>
using namespace std;
vector<int> bf[21];
int n, k, mx;
bool matched[21];

void dfs(int a) {
	if (a == n + 1) {
		mx = max(mx, k + (n > k));
		return;
	}
	if (!matched[a]) {
		for (int e : bf[a]) {
			if (matched[e]) continue;

			matched[e] = true;
			matched[a] = true;
			k += 2;
			dfs(a + 1);
			k -= 2;
			matched[e] = false;
			matched[a] = false;
		}
	}
	dfs(a + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		bf[a].push_back(b);
		bf[b].push_back(a);
	}

	dfs(0);

	cout << mx;
}