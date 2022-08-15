#include <bits/stdc++.h>
using namespace std;
int a[20], D[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cin >> m;
		D[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= m; j++) {
				D[j] += D[j - a[i]];
			}
		}
		
		cout << D[m] << '\n';
		fill(D, D + m + 1, 0);
	}
}