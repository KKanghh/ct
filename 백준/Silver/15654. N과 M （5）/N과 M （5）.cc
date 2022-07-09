#include <bits/stdc++.h>
using namespace std;
int arr[9], n, m, res[9];
bool isused[9];
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << res[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			res[k] = arr[i];
			isused[i] = true;
			func(k + 1);
			isused[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);

}
