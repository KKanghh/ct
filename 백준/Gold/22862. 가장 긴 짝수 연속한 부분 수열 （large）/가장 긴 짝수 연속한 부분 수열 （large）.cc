#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int odd = k;
	int en = 0;
	int mx = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && (a[en] % 2 == 0 || (a[en] % 2 == 1 && k > 0))) {
			k -= a[en++] % 2;
		}
		mx = max(mx, en - st - (odd - k));
		k += a[st] % 2;
	}

	cout << mx;
}