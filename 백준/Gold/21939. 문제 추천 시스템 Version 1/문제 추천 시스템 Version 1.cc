#include <bits/stdc++.h>
using namespace std;
map<int, int> hard;
set<int> pr[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;
	while (n--) {
		int p, l;
		cin >> p >> l;
		pr[l].insert(p);
		hard[p] = l;
	}

	cin >> m;
	while (m--) {
		string command;
		cin >> command;
		if (command == "add") {
			int p, l;
			cin >> p >> l;
			pr[l].insert(p);
			hard[p] = l;
		} 
		else if (command == "recommend") {
			int x;
			cin >> x;
			if (x == 1) {
				for (int i = 100; i > 0; i--) {
					if (!pr[i].empty()) {
						cout << *prev(pr[i].end()) << '\n';
						break;
					}
				}
			}
			else {
				for (int i = 1; i <= 100; i++) {
					if (!pr[i].empty()) {
						cout << *pr[i].begin() << '\n';
						break;
					}
				}
			}
		}
		else {
			int p;
			cin >> p;
			int l = hard[p];
			pr[l].erase(p);
			hard.erase(p);
		}
	}
}