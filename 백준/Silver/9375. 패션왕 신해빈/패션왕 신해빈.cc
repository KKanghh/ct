#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		map<string, int> clothes;
		int n;
		cin >> n;
		while (n--) {
			string k, type;
			cin >> k >> type;
			if (clothes.count(type)) clothes[type]++;
			else clothes[type] = 1;
		}

		int cnt = 1;
		for (auto e : clothes) cnt *= (e.second + 1);
		cout << cnt - 1 << '\n';
	}
}