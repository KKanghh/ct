#include <bits/stdc++.h>
using namespace std;
int rnk[501], after[501];
//set<int> S[501];
vector<pair<int, int>> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		vector<int> ans;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int p;
			cin >> p;
			rnk[p] = i;
		}

		int m;
		cin >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			V.push_back({ a, b });
		}

		for (int i = 1; i <= n; i++) after[i] = rnk[i];

		for (auto e : V) {
			if (rnk[e.first] < rnk[e.second]) {
				after[e.first]++;
				after[e.second]--;
			}
			else {
				after[e.first]--;
				after[e.second]++;
			}
		}
		V.clear();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (after[j] == i) ans.push_back(j);
			}

			if (ans.size() == i) continue;
			if (ans.size() < i) cout << "IMPOSSIBLE\n";
			break;
		}

		if (ans.size() < n) continue;
		for (int e : ans) cout << e << ' ';
		cout << '\n';
	}
}