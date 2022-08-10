#include <bits/stdc++.h>
using namespace std;
int D[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> D[i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i / 2; j++) {
			D[i] = max(D[i], D[j] + D[i - j]);
		}
	}

	cout << D[n];
}