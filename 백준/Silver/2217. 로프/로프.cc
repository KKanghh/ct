#include <bits/stdc++.h>
using namespace std;
int rope[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(rope[n - i] * i, mx);
	}

	cout << mx;
}