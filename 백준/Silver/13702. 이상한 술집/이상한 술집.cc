#include <bits/stdc++.h>
using namespace std;
int m[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	long long st = 0;
	long long en = 0x7fffffff;
	while (st < en) {
		long long md = (st + en + 1) / 2;
		long long d = 0;
		for (int i = 0; i < n; i++) {
			d += m[i] / md;
		}
		if (d < k) en = md - 1;
		else st = md;
	}

	cout << st;
}