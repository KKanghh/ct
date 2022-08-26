#include <bits/stdc++.h>
using namespace std;
int tree[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> tree[i];

	int st = 0, en = 1000000000;
	while (st < en) {
		int mid = (st + en + 1) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) cnt += mid < tree[i] ? tree[i] - mid : 0;
		if (cnt >= m) st = mid;
		else en = mid - 1;
	}

	cout << st;
}