#include <bits/stdc++.h>
using namespace std;
int arr[9], n, m, num[9];

void func(int k, int t) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = t; i < n; i++) {
		arr[k] = num[i];
		func(k + 1, i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0, 0);
}