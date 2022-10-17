#include <bits/stdc++.h>
using namespace std;
int d[10];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> d[i];

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		cnt += k / d[i];
		k %= d[i];
	}

	cout << cnt;
}