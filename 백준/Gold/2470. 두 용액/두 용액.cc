#include <bits/stdc++.h>
using namespace std;
int num[100000];
int mn = INT_MAX;
int a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];

	sort(num, num + n);

	for (int i = 0; i < n; i++) {
		int p = lower_bound(num, num + n, -num[i]) - num;
		if (p < n && p != i && abs(num[i] + num[p]) < mn) {
			mn = abs(num[i] + num[p]);
			a = min(i, p);
			b = max(i, p);
		}
		if (p > 0 && p != i + 1 && abs(num[i] + num[p - 1]) < mn) {
			mn = abs(num[i] + num[p - 1]);
			a = min(i, p - 1);
			b = max(i, p - 1);
		}
	}

	cout << num[a] << ' ' << num[b];

}