#include <bits/stdc++.h>
using namespace std;
int arr[9], n, m, res[9];

void func(int k, int t) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
	}
	for (int i = t; i < n; i++) {
		res[k] = arr[i];
		func(k + 1, i + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0, 0);
}