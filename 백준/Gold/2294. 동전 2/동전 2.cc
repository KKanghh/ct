#include <bits/stdc++.h>
using namespace std;
int a[100], D[10001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n, k;
	cin >> n >> k;
	fill(D, D + k + 1, k + 2);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	D[0] = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > k) continue;
		for (int j = a[i]; j <= k; j++) {
			D[j] = min(D[j], D[j - a[i]] + 1);
		}
	}
	
	//for (int i = 0; i <= k; i++) cout << D[i] << ' ';
	//cout << '\n';

	if (D[k] == k + 2) cout << -1;
	else cout << D[k];
}