#include <bits/stdc++.h>
using namespace std;

int a[10002], D[10002][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	D[1][0] = a[1];
	D[1][1] = a[1];
	D[2][0] = a[2];
	D[2][1] = a[1] + a[2];

	if (n == 1) {
		cout << a[1];
		return 0;
	}
	if (n == 2) {
		cout << a[2] + a[1];
		return 0;
	}
	int mx = 0;
	for (int i = 3; i <= n; i++) {
		D[i][0] = max({ D[i - 2][0], D[i - 2][1], D[i - 3][1], D[i - 3][0] }) + a[i];
		D[i][1] = D[i - 1][0] + a[i];
		mx = max(mx, D[i][0]);
		mx = max(mx, D[i][1]);
	}
	cout << max({ D[n][0], D[n][1], D[n - 1][1] });
}