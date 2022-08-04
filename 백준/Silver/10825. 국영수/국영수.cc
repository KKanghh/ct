#include <bits/stdc++.h>
using namespace std;

vector<tuple<string, int, int, int>> V;

bool cmp(tuple<string, int, int, int>& a, tuple<string, int, int, int>& b) {
	string n1, n2;
	int k1, e1, m1, k2, e2, m2;
	tie(n1, k1, e1, m1) = a;
	tie(n2, k2, e2, m2) = b;
	if (k1 == k2) {
		if (e1 == e2) {
			if (m1 == m2) {
				return a < b;
			}
			return m1 > m2;
		}
		return e1 < e2;
	}
	return k1 > k2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--) {
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;
		V.push_back({ name, k, e, m });
	}

	sort(V.begin(), V.end(), cmp);
	for (auto e : V) cout << get<0>(e) << '\n';
}