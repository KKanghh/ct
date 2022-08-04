#include <bits/stdc++.h>
using namespace std;
int D[41][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	D[0][0] = 1;
	D[0][1] = 0;
	D[1][0] = 0;
	D[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		D[i][0] = D[i - 1][0] + D[i - 2][0];
		D[i][1] = D[i - 1][1] + D[i - 2][1];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << D[n][0] << ' ' << D[n][1] << '\n';
	}
}