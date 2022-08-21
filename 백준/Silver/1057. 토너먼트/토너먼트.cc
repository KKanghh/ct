#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, a, b;
	cin >> k >> a >> b;
	int mn = min(a, b);
	int mx = max(a, b);
	int r = 0;
	while (mx != mn) {
		mn = (mn + 1) / 2;
		mx = (mx + 1) / 2;
		r++;
	}

	cout << r;
}