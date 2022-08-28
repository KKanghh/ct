#include <bits/stdc++.h>
using namespace std;
int arr[2000], n;
vector<int> sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int k = arr[i] + arr[j];
			if (k == arr[i] || k == arr[j]) {
				int t = upper_bound(arr, arr + n, k) - lower_bound(arr, arr + n, k);
				t -= (k == arr[i]) + (k == arr[j]);
				if (t <= 0) continue;
			}
			sum.push_back(arr[i] + arr[j]);
		}
	}

	sort(sum.begin(), sum.end());
	sum.erase(unique(sum.begin(), sum.end()), sum.end());

	for (int e : sum) {
		int a = lower_bound(arr, arr + n, e) - arr;
		int b = upper_bound(arr, arr + n, e) - arr;
		cnt += b - a;
	}
	cout << cnt;
}