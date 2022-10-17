#include <bits/stdc++.h>
using namespace std;
int D[1001][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		D[i][0] = 1;
		for (int j = 1; j <= 9; j++) {
			D[i][j] = D[i - 1][j] + D[i][j - 1] % 10007;
		}
	}

	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		cnt += D[n][i];
		cnt %= 10007;
	}

	cout << cnt;

}