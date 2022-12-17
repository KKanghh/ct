#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> V;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;

	cin >> n >> l;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		V.push_back({ a, b });
	}

	sort(V.begin(), V.end());

	int k = 0;

	for (auto cur : V) {
		if (k >= cur.Y) {
			continue;
		}
		if (k > cur.X) {
			cur.X = k;
		}
		int len = cur.Y - cur.X;
		k = cur.X + ((len - 1) / l + 1) * l;
		cnt += ((len - 1) / l + 1);
	}

	cout << cnt;
}