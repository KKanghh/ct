#include <bits/stdc++.h>
using namespace std;
int m, n;
int snack[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	
	for (int i = 0; i < n; i++) cin >> snack[i];

	int st = 0, en = 1000000000;
	while (st < en) {
		int mid = (st + en + 1) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += snack[i] / mid;
		if (cnt >= m) st = mid;
		else en = mid - 1;
	}
	cout << st;
}