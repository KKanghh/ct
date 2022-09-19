#include <bits/stdc++.h>
using namespace std;
multiset<int> bag;
vector<pair<int, int>> jewel; // 가격 - 무게

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	while (n--) {
		int m, v;
		cin >> m >> v;
		jewel.push_back({ v, m });
	}

	while (k--) {
		int c;
		cin >> c;
		bag.insert(c);
	}
	sort(jewel.begin(), jewel.end(), greater<pair<int, int>>());

	long long cnt = 0;
	for (auto e: jewel) {
		auto it = bag.lower_bound(e.second);
		if (it != bag.end()) {
			cnt += e.first;
			bag.erase(it);
		}

		if (bag.empty()) break;
	}

	cout << cnt;
}