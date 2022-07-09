#include <bits/stdc++.h>
using namespace std;
int arr[9], n, m;
void func(int k, int t) {
	if (k == m) {
		for (int i = 0; i < k; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = t; i <= n; i++) {
		arr[k] = i;
		func(k + 1, i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0, 1);
}