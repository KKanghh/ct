#include <bits/stdc++.h>
using namespace std;
short arr[10000], n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int k = arr[i] + arr[j];
			int a = lower_bound(arr, arr + n, -k) - arr;
			int b = upper_bound(arr, arr + n, -k) - arr;

			cnt += b - a;
			if (a <= i && i < b) cnt--;
			if (a <= j && j < b) cnt--;
		}
	}

	cout << cnt / 3;
}