#include <bits/stdc++.h>
using namespace std;
int n, arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int a = 0, b = 0, mn = INT_MAX;

	for (int i = 0; i < n; i++) {
		int st = 0, en = n - 1;
		while (st + 1< en) {
			int mid = (st + en + 1) / 2;
			if (arr[mid] + arr[i] == 0) {
				st = mid;
				en = mid;
			}
			if (arr[mid] + arr[i] < 0) st = mid;
			else en = mid;
		}
		if (abs(arr[i] + arr[st]) < mn && i != st) {
			mn = abs(arr[i] + arr[st]);
			a = i;
			b = st;
		}
		if (abs(arr[i] + arr[en]) < mn && i != en) {
			mn = abs(arr[i] + arr[en]);
			a = i;
			b = en;
		}
	}

	cout << min(arr[a], arr[b]) << ' ' << max(arr[a], arr[b]);
}