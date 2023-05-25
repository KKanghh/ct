#include <bits/stdc++.h>
using namespace std;
int num[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];

	int a = 0, b = 0;
	int mx = INT_MAX;

	for (int i = 0; i < n; i++) {
		int p = upper_bound(num, num + n, -num[i]) - num;
		if (p < n && p != i && abs(num[i] + num[p]) < mx) {
			mx = abs(num[i] + num[p]);
			a = min(i, p);
			b = max(i, p);
		}
		if (p > 0 && p != i + 1 && abs(num[i] + num[p - 1]) < mx) {
			mx = abs(num[i] + num[p - 1]);
			a = min(i, p - 1);
			b = max(i, p - 1);
			
		}
	}

	cout << num[a] << ' ' << num[b];
}