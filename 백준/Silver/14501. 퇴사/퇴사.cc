#include <bits/stdc++.h>
using namespace std;
int T[17], P[17], D[17];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}
	
	for (int i = 1; i <= n; i++) {
		D[i] = max(D[i - 1], D[i]);
		if (i + T[i] > n + 1) continue;
		D[i + T[i]] = max(D[i] + P[i], D[i + T[i]]);
	}
	D[n + 1] = max(D[n], D[n + 1]);
	cout << D[n + 1];
	//cout << *max_element(D, D + n + 2);
}