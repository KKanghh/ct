#include <bits/stdc++.h>
using namespace std;
int a[50], b[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a + n);
	sort(b, b + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += b[i] * a[n - 1 - i];
	}

	cout << cnt;
}