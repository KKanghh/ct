#include <bits/stdc++.h>
using namespace std;
int D[21][2], A[21][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> A[i][0] >> A[i][1];
	}
	int k;
	cin >> k;

	D[2][0] = A[1][0];
	D[2][1] = D[2][0];
	D[3][0] = min(D[2][0] + A[2][0], D[1][0] + A[1][1]);
	D[3][1] = D[3][0];
	for (int i = 4; i <= n; i++) {
		D[i][0] = min(D[i - 1][0] + A[i - 1][0], D[i - 2][0] + A[i - 2][1]);
		D[i][1] = min({ D[i - 1][1] + A[i - 1][0], D[i - 2][1] + A[i - 2][1], D[i - 3][0] + k });
	}

	cout << min(D[n][0], D[n][1]);
}