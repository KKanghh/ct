#include <bits/stdc++.h>
using namespace std;
int a[101], D[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	D[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= m; j++) {
			D[j] += D[j - a[i]];
		}
	}
	
	cout << D[m];
}