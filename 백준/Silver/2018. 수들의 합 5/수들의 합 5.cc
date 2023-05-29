#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int en = 1;
	int sum = 0, cnt = 0;

	for (int st = 1; st <= n; st++) {
		while (sum < n) sum += en++;
		if (sum == n) cnt++;
		sum -= st;
	}

	cout << cnt;
}