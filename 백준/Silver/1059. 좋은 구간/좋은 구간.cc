#include <bits/stdc++.h>
using namespace std;

int num[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L, n;
	cin >> L;

	for (int i = 0; i < L; i++) cin >> num[i];
	sort(num, num + L);

	cin >> n;


	int lp = lower_bound(num, num + L, n) - num;
	int l;
	if (lp == 0) {
		l = 0;
	}
	else {
		l = num[lp - 1];
	}
	int up = upper_bound(num, num + L, n) - num;
	int u = num[up];

	if (up != lp) cout << 0;
	else cout << (n - l) * (u - n) - 1;
}