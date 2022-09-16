#include <bits/stdc++.h>
using namespace std;
map<string, vector<string>> girl;
map<string, string> k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (n--) {
		string group;
		cin >> group;
		int member;
		cin >> member;
		vector<string> S;
		for (int i = 0; i < member; i++) {
			string name;
			cin >> name;
			S.push_back(name);
			k[name] = group;
		}

		girl[group] = S;
	}

	while (m--) {
		string q;
		int type;
		cin >> q >> type;
		if (type == 0) {
			sort(girl[q].begin(), girl[q].end());
			for (string g : girl[q]) cout << g << '\n';
		}
		if (type == 1) {
			cout << k[q] << '\n';
		}
	}
}