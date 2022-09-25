#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> Q;
set<int> L[101];
set<pair<int, int>> G[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int p, l, g;
		cin >> p >> l >> g;

		Q[p] = { l, g };
		L[l].insert(p);
		G[g].insert({ l, p });
	}

	int m;
	cin >> m;
	while (m--) {
		string op;
		cin >> op;

		if (op == "recommend") {
			int g, x;
			cin >> g >> x;
			if (x == 1) {
				cout << prev(G[g].end())->second << '\n';
			}
			else {
				cout << G[g].begin()->second << '\n';
			}
		}
		else if (op == "recommend2") {
			int x;
			cin >> x;
			if (x == 1) {
				int i = 100;
				while (L[i].empty()) i--;
				cout << *prev(L[i].end()) << '\n';
			}
			else {
				int i = 1;
				while (L[i].empty()) i++;
				cout << *L[i].begin() << '\n';
			}
		}
		else if (op == "recommend3") {
			int x, l;
			cin >> x >> l;
			if (x == 1) {
				while (l <= 100 && L[l].empty()) l++;
				if (l == 101) {
					cout << -1 << '\n';
					continue;
				}
				cout << *L[l].begin() << '\n';
			}
			else {
				l--;
				while (l > 0 && L[l].empty()) l--;
				if (l == 0) {
					cout << -1 << '\n';
					continue;
				}
				cout << *prev(L[l].end()) << '\n';
			}
		}
		else if (op == "add") {
			int p, l, g;
			cin >> p >> l >> g;
			Q[p] = { l, g };
			L[l].insert(p);
			G[g].insert({ l, p });
		}
		else {
			int p, l, g;
			cin >> p;
			tie(l, g) = Q[p];
			L[l].erase(p);
			G[g].erase({ l, p });
			Q.erase(p);
		}
	}
}