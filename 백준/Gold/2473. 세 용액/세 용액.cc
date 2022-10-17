#include <bits/stdc++.h>
using namespace std;
long long arr[5000];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	long long mn = LLONG_MAX;
	int one, two, thr;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			long long k = arr[i] + arr[j];

			int cur = lower_bound(arr, arr + n, -k) - arr;
			if (cur != i && cur != j && cur < n && abs(arr[i] + arr[j] + arr[cur]) < abs(mn)) {
				mn = arr[i] + arr[j] + arr[cur];
				one = min({ i, j ,cur });
				thr = max({ i, j ,cur });
				two = i + j + cur - one - thr;
			}

			if (cur - 1 != i && cur - 1 != j && cur - 1 >= 0 && abs(arr[i] + arr[j] + arr[cur - 1]) < abs(mn)) {
				mn = arr[i] + arr[j] + arr[cur - 1];
				one = min({ i, j ,cur - 1 });
				thr = max({ i, j ,cur - 1 });
				two = i + j + (cur - 1) - one - thr;
			}

			if (cur + 1 != i && cur + 1 != j && cur + 1 < 0 && abs(arr[i] + arr[j] + arr[cur + 1]) < abs(mn)) {
				mn = arr[i] + arr[j] + arr[cur + 1];
				one = min({ i, j ,cur + 1 });
				thr = max({ i, j ,cur + 1 });
				two = i + j + (cur + 1) - one - thr;
			}
		}
	}

	cout << arr[one] << ' ' << arr[two] << ' ' << arr[thr];

}