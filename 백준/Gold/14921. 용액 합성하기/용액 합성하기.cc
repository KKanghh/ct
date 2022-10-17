#include <bits/stdc++.h>
using namespace std;
int arr[100000], n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		int k = lower_bound(arr, arr + n, -arr[i]) - arr;
		
		if (k < n && i != k && abs(mn) > abs(arr[i] + arr[k])) {
			mn = arr[i] + arr[k];
		}
		if (k - 1 >= 0 && i != k - 1 && abs(mn) > abs(arr[i] + arr[k - 1])) {
			mn = arr[i] + arr[k - 1];
		}
		if (k + 1 < n && k + 1 != i && abs(mn) > abs(arr[i] + arr[k + 1])) {
			mn = arr[i] + arr[k + 1];
		}
	}

	cout << mn;
}