#include <bits/stdc++.h>
using namespace std;
int T[1500002], P[1500002], D[1500002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i <= n; i++) {
		D[i] = max(D[i], D[i - 1]);
		if (i + T[i] <= n + 1) D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);
	}
	D[n + 1] = max(D[n], D[n + 1]);

	cout << D[n + 1];
}