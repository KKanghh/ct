#include <bits/stdc++.h>
using namespace std;

int D[41][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[0][0] = 1;
	D[1][0] = 1;
	for (int i = 2; i <= 40; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	int n, m, k = 1, cnt = 1;
	cin >> n >> m;
	n += 1;
	while (m--) {
		int t;
		cin >> t;
		cnt *= D[t - k][0] + D[t - k][1];
		k = t + 1;
	}
	cnt *= D[n - k][0] + D[n - k][1];
	cout << cnt;
}