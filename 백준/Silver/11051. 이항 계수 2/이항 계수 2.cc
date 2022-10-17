#include <bits/stdc++.h>
using namespace std;
int D[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) D[i][j] = 1;
			else {
				D[i][j] = (D[i - 1][j - 1] + D[i - 1][j]) % 10007;
			}
		}
	}
	
	cout << D[n][k];
}