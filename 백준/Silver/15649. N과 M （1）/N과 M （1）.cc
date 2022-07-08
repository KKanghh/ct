#include <bits/stdc++.h>
using namespace std;
int arr[9];
bool isused[9];
int n, m;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) cout << arr[i] << ' ';
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
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
	func(0);
}