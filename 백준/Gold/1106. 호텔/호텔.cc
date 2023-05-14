#include <bits/stdc++.h>
using namespace std;
int D[2001];
pair<int, int> p[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c, n;
	cin >> c >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	fill(D + 1, D + 2001, 0x3f3f3f3f);

	for (int i = 1; i <= 2000; i++) {
		for (int j = 0; j < n; j++) {
			if (i - p[j].second < 0) continue;

			D[i] = min(D[i], D[i - p[j].second] + p[j].first);
		}
	}

	cout << *min_element(D + c, D + 2001);
}