#include <bits/stdc++.h>
using namespace std;
int house[200000];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) cin >> house[i];
	sort(house, house + n);

	int st = 1, ed = house[n - 1] - house[0];
	for (int i = 1; i < n; i++) {
		v.push_back(house[i] - house[i - 1]);
	}

	while (st < ed) {
		int mid = (st + ed + 1) / 2;
		int cnt = 1;
		int k = mid;
		for (int e : v) {
			if (e >= k) {
				cnt++;
				k = mid;
			}
			else k -= e;
		}
		if (cnt >= c) {
			st = mid;
		}
		else {
			ed = mid - 1;
		}
	}

	cout << st;
}