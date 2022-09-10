#include <bits/stdc++.h>
using namespace std;
int a[100000];
int en;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s, mn = 0x7fffffff;
	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> a[i];
	int sum = a[0];
	for (int st = 0; st < n; st++) {
		while (en < n && sum < s) sum += a[++en];
		if (en == n) break;
		mn = min(mn, en - st + 1);
		sum -= a[st];
	}

	if (mn == 0x7fffffff) cout << 0;
	else cout << mn;
}