#include <bits/stdc++.h>
using namespace std;
long long D[2000005], a[2000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[1000000] = 0;
	D[1000001] = 1;

	for (int i = 1000002; i <= 2000000; i++) {
		D[i] = (D[i - 1] + D[i - 2]);
		a[i] = D[i] / 1000000000;
		D[i] %= 1000000000;
	}

	for (int i = 999999; i >= 0; i--) {
		D[i] = (D[i + 2] - D[i + 1]) % 1000000000;
	}

	int n;
	cin >> n;
	if (D[n + 1000000] < 0) cout << -1 << '\n';
	else if (D[n + 1000000] > 0) cout << 1 << '\n';
	else cout << 0 << '\n';
	cout << abs(D[n + 1000000]);
}