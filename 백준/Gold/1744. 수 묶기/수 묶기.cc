#include <bits/stdc++.h>
using namespace std;
int a[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int neg = 0, pos = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= 0) neg++;
		else if (a[i] > 1) pos++;
	}

	sort(a, a + n);
	
	int cnt = 0, i = 0;
	while (a[i] <= 0) {
		if (a[i] <= 0 && i + 1 < n && a[i + 1] <= 0) {
			cnt += a[i] * a[i + 1];
			i += 2;
		}
		else {
			cnt += a[i];
			i++;
		}
	}
	int j = n - 1;

	while (a[j] > 1) {
		if (a[j] > 1 && j - 1 >= 0 && a[j - 1] > 1) {
			cnt += a[j] * a[j - 1];
			j -= 2;
		}
		else {
			cnt += a[j];
			j--;
		}
	}

	for (int k = i; k <= j; k++) {
		cnt += a[k];
	}

	cout << cnt;
}