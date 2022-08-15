#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char a[1001][1001];
int D[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;
	int mx = 0;
	fill(a[0], a[0] + m, '0');
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j == 0) {
				a[i][j] = '0';
				continue;
			}
			cin >> a[i][j];
			if (a[i][j] == '1') {
				if (a[i - 1][j] == a[i - 1][j - 1] && a[i - 1][j - 1] == a[i][j - 1]) {
					D[i][j] = min({ D[i - 1][j - 1], D[i - 1][j], D[i][j - 1] }) + 1;
				}
				else {
					D[i][j] = 1;
				}
				mx = max(mx, D[i][j] * D[i][j]);
			}
		}
	}

	cout << mx;

}