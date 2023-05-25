#include <bits/stdc++.h>
using namespace std;
int D[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	D[0] = 1;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		for (int j = t; j <= k; j++) D[j] += D[j - t];
	}

	cout << D[k];
}