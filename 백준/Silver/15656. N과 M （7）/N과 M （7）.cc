#include <bits/stdc++.h>
using namespace std;
int arr[8], n, m, num[8];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[k] = num[i];
		func(k + 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);
}