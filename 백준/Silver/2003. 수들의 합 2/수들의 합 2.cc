#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	int en = 0, cnt = 0;
	int sum = a[0];
	for (int st = 0; st < n; st++) {
		while (en < n && sum < m) sum += a[++en];
		if (en == n) break;
		if (sum == m) cnt++;
		sum -= a[st];
	}

	cout << cnt;
}