#include <bits/stdc++.h>
using namespace std;
int D[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, mx = -1001;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> D[i];
		if (0 <= D[i - 1]) D[i] += D[i - 1];
		mx = max(mx, D[i]);
	}

	cout << mx;
}