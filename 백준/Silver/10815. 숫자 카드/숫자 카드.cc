#include <bits/stdc++.h>
using namespace std;
int arr[500000], n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int m;
	cin >> m;

	while (m--) {
		int k;
		cin >> k;
		cout << binary_search(arr, arr + n, k) << ' ';
	}
}