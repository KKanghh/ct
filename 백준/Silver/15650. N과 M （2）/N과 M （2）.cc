#include <bits/stdc++.h>
using namespace std;
int arr[10];
bool isused[10];
int n, m;

void func(int k, int t) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = t; i <= n; i++) {
		if (!isused[i]) {
			isused[i] = true;
			arr[k] = i;
			func(k + 1, i + 1);
			isused[i] = false;
		}
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0, 1);

}